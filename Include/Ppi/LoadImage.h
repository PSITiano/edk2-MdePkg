/* @file
  The file descript the PPI which notifies other drivers 
  of the PEIM being initialized by the PEI Dispatcher.

  Copyright (c) 2006 - 2007, Intel Corporation                                                         
  All rights reserved. This program and the accompanying materials                          
  are licensed and made available under the terms and conditions of the BSD License         
  which accompanies this distribution.  The full text of the license may be found at        
  http://opensource.org/licenses/bsd-license.php                                            

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

  @par Revision Reference:
  This PPI is defined in PI.
  Version 1.00.

**/

#ifndef __LOADED_IMAGE_PPI_H__
#define __LOADED_IMAGE_PPI_H__

#define EFI_PEI_LOADED_IMAGE_PPI_GUID \
  { 0xc1fcd448, 0x6300, 0x4458, { 0xb8, 0x64, 0x28, 0xdf, 0x1, 0x53, 0x64, 0xbc } }


typedef struct _EFI_PEI_LOADED_IMAGE_PPI  EFI_PEI_LOADED_IMAGE_PPI;

/*
  This interface is installed by the PEI Dispatcher after the image has been
  loaded and after all security checks have been performed, 
  to notify other PEIMs of the files which are being loaded.

  @param  ImageAddress  Address of the image at the address where it will be executed.

  @param  ImageSize     Size of the image as it will be executed.

  @param  FileHandle    File handle from which the image was loaded. Can be NULL, 
                        indicating the image was not loaded from a handle.

**/
struct _EFI_PEI_LOADED_IMAGE_PPI {
  EFI_PHYSICAL_ADDRESS  ImageAddress;
  UINT64                ImageSize;
  EFI_PEI_FILE_HANDLE   FileHandle;
};


extern EFI_GUID gEfiPeiLoadedImagePpiGuid;

#endif
