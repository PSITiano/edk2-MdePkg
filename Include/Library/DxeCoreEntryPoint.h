/** @file
  Entry point to the DXE Core

  Copyright (c) 2006, Intel Corporation<BR>
  All rights reserved. This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __MODULE_ENTRY_POINT_H__
#define __MODULE_ENTRY_POINT_H__

//
// Declare the cache of copy of HobList. 
// 
extern VOID  *gHobList;


/**
  Enrty point to DXE core.

  @param  HobStart Pointer of HobList.

**/
VOID
EFIAPI
_ModuleEntryPoint (
  IN VOID  *HobStart
  );


/**
  Wrapper of enrty point to DXE CORE.

  @param  HobStart Pointer of HobList.

**/
VOID
EFIAPI
EfiMain (
  IN VOID  *HobStart
  );


/**
  Call constructs for all libraries. Automatics Generated by tool.

  @param  ImageHandle ImageHandle of the loaded driver.
  @param  SystemTable Pointer to the EFI System Table.

**/
VOID
EFIAPI
ProcessLibraryConstructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Call destructors for all libraries. Automatics Generated by tool.

  @param  ImageHandle ImageHandle of the loaded driver.
  @param  SystemTable Pointer to the EFI System Table.

**/
VOID
EFIAPI
ProcessLibraryDestructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Call the list of driver entry points. Automatics Generated by tool.

  @param  HobStart Pointer to HobList.
 
**/
VOID
EFIAPI
ProcessModuleEntryPointList (
  IN VOID  *HobStart
  );

#endif
