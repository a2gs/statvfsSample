/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * statvfs(2) usage sample (get filesystem information/statistics).
 *
 * Public domain
 *
 */

/* statvfs.c
 * statvfs sample
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 06/04/2019 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/types.h>


/* *** FUNCTIONS *********************************************************************** */
int main (int argc, char *argv[])
{
	struct statvfs fsInfo;

	if(argc != 2){
		printf("Usage:\n\t%s /mount/point\n", argv[0]);
		return(-1);
	}

	if(statvfs(argv[1], &fsInfo) == -1){
		printf("Erro statvfs(): [%s]\n", strerror(errno));
		return(-1);
	}

	printf("Filesystem..................................: [%s]\n", argv[1]);
	printf("Block size..................................: [%lu]\n", fsInfo.f_bsize);
	printf("Fragment size...............................: [%lu]\n", fsInfo.f_frsize);
	printf("Size of fs in f_frsize units................: [%lu]\n", fsInfo.f_blocks);
	printf("Number of free blocks.......................: [%lu]\n", fsInfo.f_bfree);
	printf("Number of free blocks for unprivileged users: [%lu]\n", fsInfo.f_bavail);
	printf("Number of inodes............................: [%lu]\n", fsInfo.f_files);
	printf("Number of free inodes.......................: [%lu]\n", fsInfo.f_ffree);
	printf("Number of free inodes forunprivileged users.: [%lu]\n", fsInfo.f_favail);
	printf("Filesystem ID...............................: [%lu]\n", fsInfo.f_fsid);
	printf("Maximum filename length.....................: [%lu]\n", fsInfo.f_namemax);
	printf("Mount flags (described below)...............: [%lu]\n", fsInfo.f_flag);

	if(ST_MANDLOCK & fsInfo.f_flag)
		printf("\tMandatory locking is permitted on the filesystem (see fcntl(2)).\n");

	if(ST_NOATIME & fsInfo.f_flag)
		printf("\tDo not update access times; see mount(2).\n");

	if(ST_NODEV & fsInfo.f_flag)
		printf("\tDisallow access to device special files on this filesystem.\n");

	if(ST_NODIRATIME & fsInfo.f_flag)
		printf("\tDo not update directory access times; see mount(2).\n");

	if(ST_NOEXEC & fsInfo.f_flag)
		printf("\tExecution of programs is disallowed on this filesystem.\n");

	if(ST_NOSUID & fsInfo.f_flag)
		printf("\tThe set-user-ID and set-group-ID bits are ignored by exec(3) for executable files on this filesystem.\n");

	if(ST_RDONLY & fsInfo.f_flag)
		printf("\tThis filesystem is mounted read-only.\n");

	if(ST_RELATIME & fsInfo.f_flag)
		printf("\tUpdate atime relative to mtime/ctime; see mount(2).\n");

	if(ST_SYNCHRONOUS & fsInfo.f_flag)
		printf("\tWrites are synched to the filesystem immediately (see the description of O_SYNC in open(2)).\n");

	return(0);
}
