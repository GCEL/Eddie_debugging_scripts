#include <stdio.h>
#include <fcntl.h>
main()
{
    printf("nfs_lock2 program starting...\n");
    int fd , ret;
    struct flock strlock;
    printf("nfs_lock2 program attempting open...\n");
    fd = open("testfile", O_CREAT | O_RDWR , 0666 );
    if (fd == -1)
       {
        printf("FATAL ERROR: Could not open file\n");
        exit(-1);
       }
        /* Set a write lock on the first 1024 butes of the file.
             It doesn't matter that they don't actually exist yet. */
      printf("nfs_lock2 program attempting lock...\n");
      strlock.l_type = F_WRLCK;
      strlock.l_whence = 0;
      strlock.l_start = 0L;
      strlock.l_len = 1024L;
      ret = fcntl (fd, F_SETLK , &strlock);
     if (ret == -1)
        {
         printf("FATAL ERROR: Could not lock file\n");
         exit(-1);
        }
      printf("nfs_lock2 program attempting close...\n");
      ret = close( fd );
      if (ret == -1)
         {
          printf("FATAL ERROR: Could not close file\n");
          exit(-1);
         }
    printf("nfs_lock2 program exiting.\n");
}


