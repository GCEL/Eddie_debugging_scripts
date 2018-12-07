program main
implicit none
include 'mpif.h'

integer i, size, rank, namelen, ierr, istatus
integer ifileHandle ! returned by MPI_FILE_OPEN
character*(MPI_MAX_PROCESSOR_NAME) name
character*160 filename
integer stat(MPI_STATUS_SIZE)

call MPI_INIT (ierr)

call MPI_COMM_SIZE (MPI_COMM_WORLD, size, ierr)
call MPI_COMM_RANK (MPI_COMM_WORLD, rank, ierr)
call MPI_GET_PROCESSOR_NAME (name, namelen, ierr)

filename='partition.inp'
! Open file
call MPI_FILE_OPEN(MPI_COMM_WORLD, filename, MPI_MODE_CREATE+MPI_MODE_WRONLY,MPI_INFO_NULL, ifileHandle, ierr)
! Write node names to file
call MPI_FILE_WRITE(ifileHandle,name,MPI_MAX_PROCESSOR_NAME,MPI_CHARACTER,istatus,ierr)
! Close file
CALL MPI_FILE_CLOSE(ifileHandle,ierr)

call MPI_FINALIZE (ierr)

end
