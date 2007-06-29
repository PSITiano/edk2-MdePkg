/** @file
  I/O Library MMIO Buffer Functions.

  Copyright (c) 2007, Intel Corporation<BR>
  All rights reserved. This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

//
// Include common header file for this module.
//
#include "BaseIoLibIntrinsicInternal.h"

/**
  Copy data from MMIO region to system memory by using 8-bit access.

  Copy data from MMIO region specified by starting address StartAddress 
  to system memory specified by Buffer by using 8-bit access. The total 
  number of byte to be copied is specified by Length. Buffer is returned.
  
  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().


  @param  StartAddress    Starting address for the MMIO region to be copied from.
  @param  Length          Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer receiving the data read.

  @return Buffer

**/
UINT8 *
EFIAPI
MmioReadBuffer8 (
  IN  UINTN       StartAddress,
  IN  UINTN       Length,
  OUT UINT8       *Buffer
  )
{
  UINT8   *ReturnBuffer;

  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));
 
  ReturnBuffer = Buffer;
  
  while (Length--) {
    *(Buffer++) = MmioRead8 (StartAddress++);
  }

  return ReturnBuffer;
}

/**
  Copy data from MMIO region to system memory by using 16-bit access.

  Copy data from MMIO region specified by starting address StartAddress 
  to system memory specified by Buffer by using 16-bit access. The total 
  number of byte to be copied is specified by Length. Buffer is returned.
  
  If StartAddress is not aligned on a 16-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().

  If Length is not aligned on a 16-bit boundary, then ASSERT().
  If Buffer is not aligned on a 16-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied from.
  @param  Length          Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer receiving the data read.

  @return Buffer

**/
UINT16 *
EFIAPI
MmioReadBuffer16 (
  IN  UINTN       StartAddress,
  IN  UINTN       Length,
  OUT UINT16      *Buffer
  )
{
  UINT16    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT16) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT16) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT16) - 1)) == 0);
 
  ReturnBuffer = Buffer;
  
  while (Length) {
    *(Buffer++) = MmioRead16 (StartAddress);
    StartAddress += sizeof (UINT16);
    Length -= sizeof (UINT16);
  }

  return ReturnBuffer;
}

/**
  Copy data from MMIO region to system memory by using 32-bit access.

  Copy data from MMIO region specified by starting address StartAddress 
  to system memory specified by Buffer by using 32-bit access. The total 
  number of byte to be copied is specified by Length. Buffer is returned.
  
  If StartAddress is not aligned on a 32-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().

  If Length is not aligned on a 32-bit boundary, then ASSERT().
  If Buffer is not aligned on a 32-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied from.
  @param  Length          Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer receiving the data read.

  @return Buffer

**/
UINT32 *
EFIAPI
MmioReadBuffer32 (
  IN  UINTN       StartAddress,
  IN  UINTN       Length,
  OUT UINT32      *Buffer
  )
{
  UINT32    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT32) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT32) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT32) - 1)) == 0);
 
  ReturnBuffer = Buffer;
  
  while (Length) {
    *(Buffer++) = MmioRead32 (StartAddress);
    StartAddress += sizeof (UINT32);
    Length -= sizeof (UINT32);
  }

  return ReturnBuffer;
}

/**
  Copy data from MMIO region to system memory by using 64-bit access.

  Copy data from MMIO region specified by starting address StartAddress 
  to system memory specified by Buffer by using 64-bit access. The total 
  number of byte to be copied is specified by Length. Buffer is returned.
  
  If StartAddress is not aligned on a 64-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS - Buffer + 1), then ASSERT().

  If Length is not aligned on a 64-bit boundary, then ASSERT().
  If Buffer is not aligned on a 64-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied from.
  @param  Length          Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer receiving the data read.

  @return Buffer

**/
UINT64 *
EFIAPI
MmioReadBuffer64 (
  IN  UINTN       StartAddress,
  IN  UINTN       Length,
  OUT UINT64      *Buffer
  )
{
  UINT64    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT64) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT64) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT64) - 1)) == 0);
 
  ReturnBuffer = Buffer;
  
  while (Length) {
    *(Buffer++) = MmioRead64 (StartAddress);
    StartAddress += sizeof (UINT64);
    Length -= sizeof (UINT64);
  }

  return ReturnBuffer;
}


/**
  Copy data from system memory to MMIO region by using 8-bit access.

  Copy data from system memory specified by Buffer to MMIO region specified 
  by starting address StartAddress by using 8-bit access. The total number 
  of byte to be copied is specified by Length. Buffer is returned.
  
  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().


  @param  StartAddress    Starting address for the MMIO region to be copied to.
  @param  Length     Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer containing the data to write.

  @return Size in bytes of the copy.

**/
UINT8 *
EFIAPI
MmioWriteBuffer8 (
  IN  UINTN         StartAddress,
  IN  UINTN         Length,
  IN  CONST UINT8   *Buffer
  )
{
  VOID* ReturnBuffer;

  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));
 
  ReturnBuffer = (UINT8 *) Buffer;
  
  while (Length--) {
     MmioWrite8 (StartAddress++, *(Buffer++));
  }

  return ReturnBuffer;
 
}

/**
  Copy data from system memory to MMIO region by using 16-bit access.

  Copy data from system memory specified by Buffer to MMIO region specified 
  by starting address StartAddress by using 16-bit access. The total number 
  of byte to be copied is specified by Length. Length is returned.
  
  If StartAddress is not aligned on a 16-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().

  If Length is not aligned on a 16-bit boundary, then ASSERT().

  If Buffer is not aligned on a 16-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied to.
  @param  Length     Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer containing the data to write.

  @return Size in bytes of the copy.

**/
UINT16 *
EFIAPI
MmioWriteBuffer16 (
  IN  UINTN        StartAddress,
  IN  UINTN        Length,
  IN  CONST UINT16 *Buffer
  )
{
  UINT16    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT16) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT16) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT16) - 1)) == 0);

  ReturnBuffer = (UINT16 *) Buffer;
  
  while (Length) {
    MmioWrite16 (StartAddress, *(Buffer++));
    
    StartAddress += sizeof (UINT16);
    Length -= sizeof (UINT16);
  }

  return ReturnBuffer;
}


/**
  Copy data from system memory to MMIO region by using 32-bit access.

  Copy data from system memory specified by Buffer to MMIO region specified 
  by starting address StartAddress by using 32-bit access. The total number 
  of byte to be copied is specified by Length. Length is returned.
  
  If StartAddress is not aligned on a 32-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().

  If Length is not aligned on a 32-bit boundary, then ASSERT().

  If Buffer is not aligned on a 32-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied to.
  @param  Length     Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer containing the data to write.

  @return Size in bytes of the copy.

**/
UINT32 *
EFIAPI
MmioWriteBuffer32 (
  IN  UINTN        StartAddress,
  IN  UINTN        Length,
  IN  CONST UINT32 *Buffer
  )
{
  UINT32    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT32) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT32) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT32) - 1)) == 0);

  ReturnBuffer = (UINT32 *) Buffer;
  
  while (Length) {
    MmioWrite32 (StartAddress, *(Buffer++));
    
    StartAddress += sizeof (UINT32);
    Length -= sizeof (UINT32);
  }

  return ReturnBuffer;
}

/**
  Copy data from system memory to MMIO region by using 64-bit access.

  Copy data from system memory specified by Buffer to MMIO region specified 
  by starting address StartAddress by using 64-bit access. The total number 
  of byte to be copied is specified by Length. Length is returned.
  
  If StartAddress is not aligned on a 64-bit boundary, then ASSERT().

  If Length is greater than (MAX_ADDRESS - StartAddress + 1), then ASSERT(). 
  If Length is greater than (MAX_ADDRESS -Buffer + 1), then ASSERT().

  If Length is not aligned on a 64-bit boundary, then ASSERT().

  If Buffer is not aligned on a 64-bit boundary, then ASSERT().

  @param  StartAddress    Starting address for the MMIO region to be copied to.
  @param  Length     Size in bytes of the copy.
  @param  Buffer          Pointer to a system memory buffer containing the data to write.

  @return Size in bytes of the copy.

**/
UINT64 *
EFIAPI
MmioWriteBuffer64 (
  IN  UINTN        StartAddress,
  IN  UINTN        Length,
  IN  CONST UINT64 *Buffer
  )
{
  UINT64    *ReturnBuffer;

  ASSERT ((StartAddress & (sizeof (UINT64) - 1)) == 0);
  
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - StartAddress));
  ASSERT ((Length - 1) <=  (MAX_ADDRESS - (UINTN) Buffer));

  ASSERT ((Length & (sizeof (UINT64) - 1)) == 0);
  ASSERT (((UINTN) Buffer & (sizeof (UINT64) - 1)) == 0);

  ReturnBuffer = (UINT64 *) Buffer;
  
  while (Length) {
    MmioWrite64 (StartAddress, *(Buffer++));
    
    StartAddress += sizeof (UINT64);
    Length -= sizeof (UINT64);
  }

  return ReturnBuffer;
}

