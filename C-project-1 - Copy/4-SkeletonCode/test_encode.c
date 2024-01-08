#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<string.h>
#include "decode.h"
int main(int argc,char *argv[])
{
   if((check_operation_type(argv)==e_encode))
   {
       printf("Selected encoding\n");
       EncodeInfo encInfo;
       if(read_and_validate_encode_args(argv,&encInfo)==e_success)
       {
           printf("Read and validate is a success\n");
           if(do_encoding(&encInfo)==e_success)
           {
               printf("Encoding is Successful\n");
           }
           else
           {
               printf("Encoding is failure");
           }

       }
       else
       {
           printf("Read and validate was a failure\n");
           return 1;
       }
   }
   else if(check_operation_type(argv)==e_decode)
   {
       printf("Selected decoding\n");
       DecodeInfo decInfo;
					if (read_and_validate_decode_args(argc, argv, &decInfo) == e_success)
					{ 
						if (do_decoding(&decInfo) == e_success)
						{
							printf("INFO: ## Decoding Done Successfully ##\n");
							fclose(decInfo.fptr_stego_image);
							fclose(decInfo.fptr_output_file);
						}
						else
						{
							fprintf(stderr,"Error: %s function failed\n","do_decoding()");
							return e_failure;
						}
					}
   }
   else
   {
       printf("Invalid input\nFor encoding:\n ./a.out -e beautiful.bmp secret.txt\nFor decoding:\n./a.out -d stego.bmp");
   }
   
   /*   EncodeInfo encInfo;
    uint img_size;

    // Fill with sample filenames
    encInfo.src_image_fname = "beautiful.bmp";
    encInfo.secret_fname = "secret.txt";
    encInfo.stego_image_fname = "stego_img.bmp";

    // Test open_files
    if (open_files(&encInfo) == e_failure)
    {
    	printf("ERROR: %s function failed\n", "open_files" );
    	return 1;
    }
    else
    {
    	printf("SUCCESS: %s function completed\n", "open_files" );
    }

    // Test get_image_size_for_bmp
    img_size = get_image_size_for_bmp(encInfo.fptr_src_image);
    printf("INFO: Image size = %u\n", img_size);*/

    return 0;
}

OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e")==0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1],"-d")==0)
    {
        return e_encode;
    }
    else
    {
        return e_unsupported;
    }

}
