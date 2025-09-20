# NUCLEO H743 ZI code for Ethernet communication

# Using cortex debug for debugging the code
[Link to the referenced code](https://www.astrolabe.coop/posts/tuto-debug-zephyr/)



# Configurring the FS SHELL with Zephyr RTOS 
* Enable flash
* Enable the SHELL
* Enable the File System
* Enable the File System Shell
``` yml
CONFIG_LOG=y
CONFIG_SHELL=y
CONFIG_FLASH=y
CONFIG_FLASH_MAP=y
CONFIG_FILE_SYSTEM=y
CONFIG_FILE_SYSTEM_SHELL=y
CONFIG_FILE_SYSTEM_LITTLEFS=y

# Add 256 bytes to accommodate upload command (lfs_stat overflows)
CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE=2304

# Enable file system commands
# CONFIG_MCUMGR_GRP_FS=y
CONFIG_FLASH_PAGE_LAYOUT=y
CONFIG_FS_LOG_LEVEL_DBG=y
CONFIG_HEAP_MEM_POOL_SIZE=16384
CONFIG_SHELL_LOG_LEVEL_INF=y
CONFIG_SHELL_LOG_LEVEL_DBG=y

CONFIG_DEBUG=y
```
## Enable the the flash 
## Select the storage for little FS




## Use the mount point to access to mount the file system 
``` code
fs mount littlefs /lfs1
```

## Format the FILE System 
``` yml
CONFIG_APP_WIPE_STORAGE=y
```

# Enable flash shell for to have access to the flash command 
``` yml
CONFIG_FLASH_SHELL=y
CONFIG_FLASH_SHELL_TEST_COMMANDS=y
```

## Can use the flash command to load data into a specific addresss

```bash
flash load <address> <size>
```

## Upload file in the file system

https://www.thevtool.com/mounting-littlefs-on-linux-machine/# zephyr-custom-stm32u575-board
