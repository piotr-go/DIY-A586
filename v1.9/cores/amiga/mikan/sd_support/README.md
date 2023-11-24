# SD Card support for mikan core by Piotr Gozdur

Option 1:
  Whole card is single Amiga HD.
  Remove card MBR and create partitions with HDToolBox.

Option 2:
  1 card partition = 1 Amiga HD
  Card must have MBR. Primary partitions only.
  Choose partition type "F0" for Amiga RDB.
  Example: If your card have 3 paritions [fat12, "F0", fat32] disk order on Amiga side will be ["F0", fat12, fat32] (unit 0, 1, 2).
  Warning: Do not touch you FAT disks with HDToolBox.
  For FAT support install fat95.

	FileSystem     = l:fat95
	Device         = scsi.device
	Unit           = 2 /* change unit number here */
	Flags          = 0
	LowCyl         = 0
	HighCyl        = 0
	Surfaces       = 1
	BlocksPerTrack = 1
	BlockSize      = 512
	Buffers        = 20
	BufMemType     = 1
	BootPri        = 0
	Stacksize      = 4096
	Priority       = 0
	GlobVec        = -1
	DosType        = 0x46415401

Changes:

- v0.10
  - speed
  - bug fixes

- v0.9.1
  - PDS partition support

- v0.9
  - multiple HD support
  - PFS3 support
  - ROM patching not needed
