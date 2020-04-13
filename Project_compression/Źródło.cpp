#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//This structure represents  a node of a huffman tree
struct node_of_a_huffman_tree
{
	char b;
	long long int occurence;
	node_of_a_huffman_tree *left;
	node_of_a_huffman_tree *right;
	char coding[256];
};

//This function compares two nodes of a huffman tree
int compare_node(const void* a, const void*b)
{
	return (*((node_of_a_huffman_tree **)a))->occurence - (*((node_of_a_huffman_tree **)b))->occurence;
}

//This function reads one bit from file using char as a buffer
///I have a problem with using buffer in general, but after explonation I think I rather got it
char read_bit(FILE *f, int flag)
{
	// fread has to read at least one byte, so I needed to use one char as a buffer here(mask)/////
	///!!! In first take I overlooked "at lest one byte" needed by fread, that is why it was not working properly///
	static int i = 0;
	static char mask = 0;
	static int limit = -1;
	//I know I have to search for EOF, then I look for the last occuring 1-, the sign of an end of the file  
	if (flag && limit == -1)
		for (int i = 7; i >= 0; i--)
		{
			if (mask & (1 << i))
			{
				limit = i;
				break;
			}
		}
	//If this step is done, then return -1 and inform user
	if (i == limit)
		return -1;
	//if reading current char is finished, then I have to get a new one and after that continue reading 
	if (i == 8)
		i = 0;
	if (i == 0)
	{
		mask = 0;
		fread(&mask, sizeof(mask), 1, f);
	}
	// Now it finally returns only one bit, which I was looking for
	return !!(mask & (1 << (i++)));
}

// Coding master assigns a code to each node in huffman tree
void coding_master(node_of_a_huffman_tree *start, const char *code)
{
	//left subtree has additional bit- "0"
	if (start->left)
	{
		char code_left[256] = "";
		strcpy(code_left, code);
		strcat(code_left, "0");
		coding_master(start->left, code_left);
	}
	//right subtree gets "1"
	if (start->right)
	{
		char code_right[256] = "";
		strcpy(code_right, code);
		strcat(code_right, "1");
		coding_master(start->right, code_right);
	}
	//Only in case leaves are "reached", I have to store their codes(because then I have "all leaf")/
	///I forgot about this "ending process"
	if (start->right == NULL && start->left == NULL)
		strcpy(start->coding, code);
}

//This function writes one bit to file using char as buffer
void write_bit(FILE *f, char bit, char end)
{
	// I repeat the operation I did in read_bit function- using a char to access each bit in a file
	///buffer!!!
	static int i = 0;
	static char mask = 0;
	// I overwrite bits in mask(as I want)
	if (bit == 1)
	{
		mask |= (1 << (i++));
	}
	else
		i++;
	//when previous operation ends, I have to write this char and prepare the mask for the next writing/////////////////////
	if (i == 8)
	{
		fwrite(&mask, sizeof(char), 1, f);
		i = 0;
		mask = 0;
	}
	if (end)
	{
		fwrite(&mask, sizeof(char), 1, f);
	}
}

// This is the recurrent function which is writing a tree to a file
void write_tree(FILE *f, node_of_a_huffman_tree *start)
{
	//if there are further subtrees, then function writes 0
	if (start->left != NULL)
	{
		write_bit(f, 0, 0);
		write_tree(f, start->left);
		write_tree(f, start->right);
	}
	//if not then function writes 1, it means that this is a leaf, and now I can write content of that leaf using this function
	else
	{
		write_bit(f, 1, 0);
		for (int i = 0; i < 8; i++)
		{
			write_bit(f, !!(start->b & (1 << i)), 0);
		}
	}
}

//This is a recurrent function reading the tree from a file
node_of_a_huffman_tree* read_tree(FILE *f)
{
	char inf = read_bit(f, 0);
	node_of_a_huffman_tree *newest = (node_of_a_huffman_tree *)malloc(sizeof(node_of_a_huffman_tree));
	//There will be subtrees to read as long as there is 0 in output///////////
	///I conctructed it with a mistake
	if (inf == 0)
	{
		newest->left = read_tree(f);
		newest->right = read_tree(f);
	}
	//if there is 1 in output, then I have to read a leaf with its content 
	else
	{
		newest->left = newest->right = NULL;
		newest->b = 0;
		for (int i = 0; i < 8; i++)
			newest->b |= (read_bit(f, 0) << i);
	}
	return newest;
}

//This function deallocates all memory
//Mode determinates if destroying the leaves is needed
//(in case of creating a tree, pointers to the leaves may be stored in an another array)
///In this moment I knew I had to deallocate memory, but I did it wrong, mainly because of my problem with pointers and arrays//
///So it would not be my first idea to store pointers to the laeves in an array, but it  had occured that was the best solution
void destroy_tree(node_of_a_huffman_tree *start, char mode)
{
	if (mode)
	{
		if (start == NULL)
			return;
	}
	else
		if (start->left == NULL)
			return;
	destroy_tree(start->left, mode);
	destroy_tree(start->right, mode);
	free(start);
}

int main()
{
	char input_name[100];
	char output_name[100];
	char choice;

	FILE *input = NULL;
	FILE *output = NULL;
	while (true)
	{
		printf("compression (c), decompression(d), terminate(t): ");///I had a problem with using fseek function
		fseek(stdin, SEEK_END, 0);
		scanf("%c", &choice);
		choice = toupper(choice);// no matter is "c" or "C" the program should work
		if (choice == 'T')// this allows user to abandon program 
			return 0;
		if (choice == 'C' || choice == 'D')
		{
			printf("input file: ");
			fseek(stdin, SEEK_END, 0);
			scanf("%s", input_name);
			input = fopen(input_name, "rb");
			if (input == NULL)
			{
				printf("Couldn't open the file!\n");
				continue;
			}
			printf("output file: ");
			fseek(stdin, SEEK_END, 0);
			scanf("%s", output_name);
			output = fopen(output_name, "wb");
			if (output == NULL)
			{
				printf("Couldn't open the file!\n");
				continue;
			}
		}

		if (choice == 'C')/////////////////////////////////////////compression//////////////////////////////////////
		{

			//I create an array that stores a number of appearences of each byte
			int appearence[256];
			for (int i = 0; i < 256; i++)
				appearence[i] = 0;
			char byte;

			while (fread(&byte, sizeof(char), 1, input))
			{
				appearence[byte] += 1;
			}
			//now I check how many bytes has to be encoded/////////////
			int number = 0;
			for (int i = 0; i < 256; i++)
			{
				if (appearence[i])
					number++;
			}
			//I create leaves, which represent raw data
			node_of_a_huffman_tree *leaves = (node_of_a_huffman_tree *)malloc(number * sizeof(node_of_a_huffman_tree));
			//Then I store their pointers in order to have  easier access and operation in place///
			///In this place I was helped, because I even had not an idea of storing pointers
			node_of_a_huffman_tree **pointers = (node_of_a_huffman_tree **)malloc(number * sizeof(node_of_a_huffman_tree *));
			int j = 0;
			for (int i = 0; i < 256; i++)
			{
				if (appearence[i])
				{
					leaves[j].b = i;
					leaves[j].occurence = appearence[i];
					leaves[j].left = leaves[j].right = NULL;
					pointers[j] = leaves + j;
					j++;
				}
			}
			//Finally I can create a huffman tree
			int i = 0;
			while (i < number - 1)
			{
				qsort(pointers + i, number - i, sizeof(node_of_a_huffman_tree *), compare_node);
				node_of_a_huffman_tree *small = (node_of_a_huffman_tree *)malloc(sizeof(node_of_a_huffman_tree));
				small->left = pointers[i];
				small->right = pointers[i + 1];
				small->b = 0;
				small->occurence = small->left->occurence + small->right->occurence;
				pointers[i + 1] = small;
				i++;
			}
			coding_master(pointers[number - 1], "");
			//saving huffman tree
			write_tree(output, pointers[number - 1]);
			fseek(input, 0, SEEK_SET);
			//saving content of a file using codes 
			while (fread(&byte, sizeof(char), 1, input))
			{
				int i;
				for (i = 0; i < number; i++)
					if (leaves[i].b == byte)
						break;
				int j = 0;
				while (leaves[i].coding[j] != 0)
				{
					write_bit(output, leaves[i].coding[j] - '0', 0);
					j++;
				}
			}
			//this one means end of file! (that's because our file do not necessarly
			/// I forgot that our file do not necessarly have to have length as multiple of 8!/////
			write_bit(output, 1, 1);
			destroy_tree(pointers[number - 1], 0);
			free(leaves);
			free(pointers);
			fclose(input);
			fclose(output);
		}
		else if (choice == 'D')////////////////////////////decompression////////////////////////////////////////////////
		{
			//I check the length of the compressed file/////////////////////////////////////////////////////////////////////////
			//important because its end isn't where is EOF
			//but there where is last "1"
			//so we need to know when to look for it
			fseek(input, 0, SEEK_END);
			int size = ftell(input);
			fseek(input, 0, SEEK_SET);
			//I read the huffman tree
			node_of_a_huffman_tree *start = read_tree(input);
			node_of_a_huffman_tree *current = start;
			//in one point I need to leave nested loop and I do it using variable condition///
			///I had not have an idea how to leave nested loop
			int condition = 1;
			while (condition)
			{
				while (true)
				{
					//flag informs whether I have to look for end of file
					int flag = 0;
					if (ftell(input) == size)
						flag = 1;
					//if I reach a leaf, then I can decode one byte
					if (current->left == NULL)
					{
						fwrite(&(current->b), sizeof(char), 1, output);
						current = start;
						break;
					}
					//depending on read bit I go to left or right subtree
					char b = read_bit(input, flag);
					//this means that  the final "1" is reached in a file and that is why I have to leave////////////////
					if (b == -1)
					{
						condition = 0;
						break;
					}
					if (b == 1)
						current = current->right;
					else
						current = current->left;

				}
			}
			destroy_tree(start, 1);
			fclose(output);
			fclose(input);
		}
	}
	return 0;
}