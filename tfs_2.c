#include "tfs.h"


/* implementation of assigned functions */


/* you are welcome to use helper functions of your own */



/* tfs_delete()
 *
 * deletes a closed directory entry having the given file descriptor
 *   (changes the status of the entry to unused) and releases all
 *   allocated file blocks
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is closed
 *
 * postconditions:
 *   (1) the status of the directory entry is set to unused
 *   (2) all file blocks have been set to free
 *
 * input parameter is a file descriptor
 *
 * return value is TRUE when successful or FALSE when failure
 */

unsigned int tfs_delete( unsigned int file_descriptor ){

  unsigned int i;
	file_allocation_table = (unsigned char *)&storage[256];
	for (i = 0; i < N_BYTES; i++){
		storage[i] = 0;
	}
	directory[file_descriptor].status = 0;
	directory[file_descriptor].first_block = 0;
	directory[file_descriptor].byte_offset = 0;
	directory[file_descriptor].size = 0;
	return TRUE;
}




/* tfs_read()
 *
 * reads a specified number of bytes from a file starting
 *   at the byte offset in the directory into the specified
 *   buffer; the byte offset in the directory entry is
 *   incremented by the number of bytes transferred
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * the function will read fewer bytes than specified if the
 *   end of the file is encountered before the specified number
 *   of bytes have been transferred
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *   (3) the file has allocated file blocks
 *
 * postconditions:
 *   (1) the buffer contains bytes transferred from file blocks
 *   (2) the specified number of bytes has been transferred
 *         except in the case that end of file was encountered
 *         before the transfer was complete
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 */

unsigned int tfs_read( unsigned int file_descriptor,
                       char *buffer,
                       unsigned int byte_count ){
						/*
  directory[file_descriptor].first_block = LAST_BLOCK;
	unsigned int b;
	b = directory[file_descriptor].first_block;
	int j = 0;
	for (int i = 0; i < byte_count; i++){
		if (j < BLOCK_SIZE - 1)	{
			sprintf(buffer, "%c", storage[i]);
			j++;
		}
	}
	return byte_count;
	*/
}

/* tfs_write()
 *
 * writes a specified number of bytes from a specified buffer
 *   into a file starting at the byte offset in the directory;
 *   the byte offset in the directory entry is incremented by
 *   the number of bytes transferred
 * 
 *   
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * furthermore, depending on the starting byte offset and the
 *   specified number of bytes to transfer, additional file
 *   blocks, if available, will be added to the file as needed;
 *   in this case, the size of the file will be adjusted
 *   based on the number of bytes transferred beyond the
 *   original size of the file
 *
 * the function will read fewer bytes than specified if file
 *   blocks are not available
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *
 * postconditions:
 *   (1) the file contains bytes transferred from the buffer
 *   (2) the specified number of bytes has been transferred
 *         except in the case that file blocks needed to
 *         complete the transfer were not available
 *   (3) the size of the file is increased as appropriate
 *         when transferred bytes extend beyond the previous
 *         end of the file
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 * 
 * 1. Byte offset
 * 2. Increment the byte offset by the bytes written
 * 		2a. Figure out if the total between Byte offset and new byte offset is 		
 * 			more than number of bytes in the file block
 * 		2b. Check if more file blocks are available
 * 			2bT. If file block IS available file size will be based on number
 * 				of bytes transfered beyond the original size of the file
 * 			2bF - If file block is NOT available only read the amount of blocks
 * 				available
 * 	3. Return number of bytes transferred
 * 
 */

unsigned int tfs_write( unsigned int file_descriptor, char *buffer, unsigned int byte_count ){

	// bytesTransferred is only if total byte_count is smaller than total file_descriptor size
	int bytesTransfered;
	
	// Creating a new block in file_descriptor
	directory[file_descriptor].byte_offset = tfs_seek; // sets the byte offset in a directory entry
	directory[file_descriptor].first_block = tfs_new_block; // Set address of first block
	directory[file_descriptor].size = BLOCK_SIZE; // Set first block = 128

	// Check if buffer is larger than file block create another block
	if(directory[file_descriptor].size < byte_count){
		// If it is, create another block if possible
	}
	else{
		// If not possible, only write what is in the existing blocks
	}

	printf("byte_offset = %d\n", directory[file_descriptor].byte_offset);
	printf("byte_count = %d\n", (int)byte_count);
	int totalBytes = directory[file_descriptor].byte_offset + (int)byte_count;
	unsigned int b;
	b = directory[file_descriptor].first_block;
	

	int j = 0;
	for (int i = 0; i < byte_count; i++){
		if (j < BLOCK_SIZE - 1)	{
			sprintf(storage, "%c", buffer[i]);
			j++;
		}

		else{
			file_allocation_table[b] = *storage;
			file_allocation_table[b] = tfs_new_block();
			b = file_allocation_table[b];
			j = 0;
		}
		
	}

	//file_allocation_table[b] = LAST_BLOCK;

	//directory[file_descriptor].size = byte_count;
	// file_allocation_table[b] = LAST_BLOCK;

	directory[file_descriptor].byte_offset = byte_count + 1;
	return byte_count;
}

// bool file_is_readable(unsigned int file_descriptor){

// }
// bool file_is_writable(unsigned int file_descriptor){

// }
// void file_make_readable(unsigned int file_descriptor){

// }
// void file_make_writable(unsigned int file_descriptor){

// }
