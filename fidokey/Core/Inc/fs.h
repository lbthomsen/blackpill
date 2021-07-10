/*
 * fs.h
 *
 *  Created on: Jun 19, 2021
 *      Author: lth
 */

#ifndef INC_FS_H_
#define INC_FS_H_

#include <lfs.h>

int fs_init(struct lfs_config *cfg);
int read_file(const char *path, void *buf, lfs_soff_t off, lfs_size_t len);
int write_file(const char *path, const void *buf, lfs_soff_t off, lfs_size_t len, uint8_t trunc);
int read_attr(const char *path, uint8_t attr, void *buf, lfs_size_t len);
int write_attr(const char *path, uint8_t attr, const void *buf, lfs_size_t len);
int get_file_size(const char *path);

/**
 * Get the total size (in KiB) of the file system.
 *
 * @return The total file system size.
 */
int get_fs_size(void);

/**
 * Get the used size (in KiB) of the file system.
 *
 * @return The used file system size.
 */
int get_fs_usage(void);

#endif /* INC_FS_H_ */
