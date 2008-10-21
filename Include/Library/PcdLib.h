/** @file
PCD Library Class provides PCD usage macro interface for all PCD types. It should be 
included at any module who use PCD. 

If module use dynamic/dynamicex PCD, module should be linked to PEIM/DXE library 
instance to access that PCD.
If module uses PatchableInModule type PCD, also need library instance produce LibPatchPcdSetPtr()
interface.
For FeatureFlag/Fixed PCD, macro interface is translated to an variable or macro
which is auto-generated by build tool in module's autogen.h/autogen.c

Copyright (c) 2006 - 2008, Intel Corporation. <BR>                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

**/

#ifndef __PCD_LIB_H__
#define __PCD_LIB_H__

#define PCD_MAX_SKU_ID           0x100

#define PcdToken(TokenName)                 _PCD_TOKEN_##TokenName


///
/// Feature Flag is in the form of a global constant
///
#define FeaturePcdGet(TokenName)            _PCD_GET_MODE_BOOL_##TokenName


//
// Fixed is fixed at build time
//
#define FixedPcdGet8(TokenName)             _PCD_VALUE_##TokenName
#define FixedPcdGet16(TokenName)            _PCD_VALUE_##TokenName
#define FixedPcdGet32(TokenName)            _PCD_VALUE_##TokenName
#define FixedPcdGet64(TokenName)            _PCD_VALUE_##TokenName
#define FixedPcdGetBool(TokenName)          _PCD_VALUE_##TokenName


#define FixedPcdGetPtr(TokenName)           ((VOID *)_PCD_VALUE_##TokenName)


//
// (Binary) Patch is in the form of a global variable
//
#define PatchPcdGet8(TokenName)             _gPcd_BinaryPatch_##TokenName
#define PatchPcdGet16(TokenName)            _gPcd_BinaryPatch_##TokenName
#define PatchPcdGet32(TokenName)            _gPcd_BinaryPatch_##TokenName
#define PatchPcdGet64(TokenName)            _gPcd_BinaryPatch_##TokenName
#define PatchPcdGetBool(TokenName)          _gPcd_BinaryPatch_##TokenName
#define PatchPcdGetPtr(TokenName)           ((VOID *)_gPcd_BinaryPatch_##TokenName)

#define PatchPcdSet8(TokenName, Value)      (_gPcd_BinaryPatch_##TokenName = (Value))
#define PatchPcdSet16(TokenName, Value)     (_gPcd_BinaryPatch_##TokenName = (Value))
#define PatchPcdSet32(TokenName, Value)     (_gPcd_BinaryPatch_##TokenName = (Value))
#define PatchPcdSet64(TokenName, Value)     (_gPcd_BinaryPatch_##TokenName = (Value))
#define PatchPcdSetBool(TokenName, Value)   (_gPcd_BinaryPatch_##TokenName = (Value))
#define PatchPcdSetPtr(TokenName, Size, Buffer) \
                                            LibPatchPcdSetPtr (                        \
                                              _gPcd_BinaryPatch_##TokenName,           \
                                              (UINTN)_PCD_PATCHABLE_##TokenName##_SIZE, \
                                              (Size),                                  \
                                              (Buffer)                                 \
                                              )

//
// Dynamic is via the protocol with only the TokenNumber as argument
//  It can also be Patch or Fixed type based on a build option
//
#define PcdGet8(TokenName)                  _PCD_GET_MODE_8_##TokenName
#define PcdGet16(TokenName)                 _PCD_GET_MODE_16_##TokenName
#define PcdGet32(TokenName)                 _PCD_GET_MODE_32_##TokenName
#define PcdGet64(TokenName)                 _PCD_GET_MODE_64_##TokenName
#define PcdGetPtr(TokenName)                _PCD_GET_MODE_PTR_##TokenName
#define PcdGetBool(TokenName)               _PCD_GET_MODE_BOOL_##TokenName

//
// Dynamic Set
//
#define PcdSet8(TokenName, Value)           _PCD_SET_MODE_8_##TokenName     ((Value))
#define PcdSet16(TokenName, Value)          _PCD_SET_MODE_16_##TokenName    ((Value))
#define PcdSet32(TokenName, Value)          _PCD_SET_MODE_32_##TokenName    ((Value))
#define PcdSet64(TokenName, Value)          _PCD_SET_MODE_64_##TokenName    ((Value))
#define PcdSetPtr(TokenName, SizeOfBuffer, Buffer) \
                                            _PCD_SET_MODE_PTR_##TokenName   ((SizeOfBuffer), (Buffer))
#define PcdSetBool(TokenName, Value)        _PCD_SET_MODE_BOOL_##TokenName  ((Value))

//
// Dynamic Ex is to support binary distribution
//
#define PcdGetEx8(Guid, TokenName)          LibPcdGetEx8    ((Guid), _PCD_TOKEN_##TokenName)
#define PcdGetEx16(Guid, TokenName)         LibPcdGetEx16   ((Guid), _PCD_TOKEN_##TokenName)
#define PcdGetEx32(Guid, TokenName)         LibPcdGetEx32   ((Guid), _PCD_TOKEN_##TokenName)
#define PcdGetEx64(Guid, TokenName)         LibPcdGetEx64   ((Guid), _PCD_TOKEN_##TokenName)
#define PcdGetExPtr(Guid, TokenName)        LibPcdGetExPtr  ((Guid), _PCD_TOKEN_##TokenName)
#define PcdGetExBool(Guid, TokenName)       LibPcdGetExBool ((Guid), _PCD_TOKEN_##TokenName)

//
// Dynamic Set Ex
//
#define PcdSetEx8(Guid, TokenName, Value)   LibPcdSetEx8   ((Guid), _PCD_TOKEN_##TokenName, (Value))
#define PcdSetEx16(Guid, TokenName, Value)  LibPcdSetEx16  ((Guid), _PCD_TOKEN_##TokenName, (Value))
#define PcdSetEx32(Guid, TokenName, Value)  LibPcdSetEx32  ((Guid), _PCD_TOKEN_##TokenName, (Value))
#define PcdSetEx64(Guid, TokenName, Value)  LibPcdSetEx64  ((Guid), _PCD_TOKEN_##TokenName, (Value))
#define PcdSetExPtr(Guid, TokenName, SizeOfBuffer, Buffer) \
                                            LibPcdSetExPtr ((Guid), _PCD_TOKEN_##TokenName, (SizeOfBuffer), (Buffer))
#define PcdSetExBool(Guid, TokenName, Value) \
                                            LibPcdSetExBool((Guid), _PCD_TOKEN_##TokenName, (Value))


/**
  Sets the current SKU in the PCD database to the value specified by SkuId.  SkuId is returned.

  @param[in]  SkuId The SKU value that will be used when the PCD service will retrieve and 
                    set values associated with a PCD token.

  @return Return the SKU ID that just be set.

**/
UINTN
EFIAPI
LibPcdSetSku (
  IN UINTN   SkuId
  );


/**
  Returns the 8-bit value for the token specified by TokenNumber. 

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the 8-bit value for the token specified by TokenNumber. 

**/
UINT8
EFIAPI
LibPcdGet8 (
  IN UINTN             TokenNumber
  );


/**
  Returns the 16-bit value for the token specified by TokenNumber. 

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the 16-bit value for the token specified by TokenNumber. 

**/
UINT16
EFIAPI
LibPcdGet16 (
  IN UINTN             TokenNumber
  );


/**
  Returns the 32-bit value for the token specified by TokenNumber. 

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the 32-bit value for the token specified by TokenNumber.

**/
UINT32
EFIAPI
LibPcdGet32 (
  IN UINTN             TokenNumber
  );


/**
  Returns the 64-bit value for the token specified by TokenNumber.

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the 64-bit value for the token specified by TokenNumber.

**/
UINT64
EFIAPI
LibPcdGet64 (
  IN UINTN             TokenNumber
  );


/**
  Returns the pointer to the buffer of the token specified by TokenNumber.

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the pointer to the token specified by TokenNumber.

**/
VOID *
EFIAPI
LibPcdGetPtr (
  IN UINTN             TokenNumber
  );


/**
  Returns the Boolean value of the token specified by TokenNumber. 

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the Boolean value of the token specified by TokenNumber. 

**/
BOOLEAN 
EFIAPI
LibPcdGetBool (
  IN UINTN             TokenNumber
  );


/**
  Returns the size of the token specified by TokenNumber. 

  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Returns the size of the token specified by TokenNumber. 

**/
UINTN
EFIAPI
LibPcdGetSize (
  IN UINTN             TokenNumber
  );


/**
  Returns the 8-bit value for the token specified by TokenNumber and Guid.
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid Pointer to a 128-bit unique value that designates 
              which namespace to retrieve a value from.
  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Return the UINT8.

**/
UINT8
EFIAPI
LibPcdGetEx8 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the 16-bit value for the token specified by TokenNumber and Guid.
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid Pointer to a 128-bit unique value that designates 
              which namespace to retrieve a value from.
  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Return the UINT16.

**/
UINT16
EFIAPI
LibPcdGetEx16 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the 32-bit value for the token specified by TokenNumber and Guid.
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid Pointer to a 128-bit unique value that designates 
              which namespace to retrieve a value from.
  @param[in]  TokenNumber The PCD token number to retrieve a current value for.

  @return Return the UINT32.

**/
UINT32
EFIAPI
LibPcdGetEx32 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the 64-bit value for the token specified by TokenNumber and Guid.
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid          Pointer to a 128-bit unique value that designates 
                            which namespace to retrieve a value from.
  @param[in]  TokenNumber   The PCD token number to retrieve a current value for.

  @return Return the UINT64.

**/
UINT64
EFIAPI
LibPcdGetEx64 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the pointer to the buffer of token specified by TokenNumber and Guid.
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid          Pointer to a 128-bit unique value that designates 
                            which namespace to retrieve a value from.
  @param[in]  TokenNumber   The PCD token number to retrieve a current value for.

  @return Return the VOID* pointer.

**/
VOID *
EFIAPI
LibPcdGetExPtr (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the Boolean value of the token specified by TokenNumber and Guid. 
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid          Pointer to a 128-bit unique value that designates 
                            which namespace to retrieve a value from.
  @param[in]  TokenNumber   The PCD token number to retrieve a current value for.

  @return Return the BOOLEAN.

**/
BOOLEAN
EFIAPI
LibPcdGetExBool (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Returns the size of the token specified by TokenNumber and Guid. 
  If Guid is NULL, then ASSERT(). 

  @param[in]  Guid          Pointer to a 128-bit unique value that designates 
                            which namespace to retrieve a value from.
  @param[in]  TokenNumber   The PCD token number to retrieve a current value for.

  @return Return the size.

**/
UINTN
EFIAPI
LibPcdGetExSize (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber
  );


/**
  Sets the 8-bit value for the token specified by TokenNumber 
  to the value specified by Value.  Value is returned.
  
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 8-bit value to set.

  @return Return the value been set.

**/
UINT8
EFIAPI
LibPcdSet8 (
  IN UINTN             TokenNumber,
  IN UINT8             Value
  );


/**
  Sets the 16-bit value for the token specified by TokenNumber 
  to the value specified by Value.  Value is returned.
  
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 16-bit value to set.

  @return Return the value been set.

**/
UINT16
EFIAPI
LibPcdSet16 (
  IN UINTN             TokenNumber,
  IN UINT16            Value
  );


/**
  Sets the 32-bit value for the token specified by TokenNumber 
  to the value specified by Value.  Value is returned.
  
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 32-bit value to set.

  @return Return the value been set.

**/
UINT32
EFIAPI
LibPcdSet32 (
  IN UINTN             TokenNumber,
  IN UINT32            Value
  );


/**
  Sets the 64-bit value for the token specified by TokenNumber 
  to the value specified by Value.  Value is returned.
  
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 64-bit value to set.

  @return Return the value been set.

**/
UINT64
EFIAPI
LibPcdSet64 (
  IN UINTN             TokenNumber,
  IN UINT64            Value
  );


/**
  Sets a buffer for the token specified by TokenNumber to the value 
  specified by Buffer and SizeOfBuffer.  Buffer is returned.  
  If SizeOfBuffer is greater than the maximum size support by TokenNumber, 
  then set SizeOfBuffer to the maximum size supported by TokenNumber and 
  return NULL to indicate that the set operation was not actually performed.  

  If SizeOfBuffer is set to MAX_ADDRESS, then SizeOfBuffer must be set to the 
  maximum size supported by TokenName and NULL must be returned.
  
  If SizeOfBuffer is NULL, then ASSERT().
  If SizeOfBuffer > 0 and Buffer is NULL, then ASSERT().
  
  @param[in]      TokenNumber   The PCD token number to set a current value for.
  @param[in,out]  SizeOfBuffer  The size, in bytes, of Buffer.
  @param[in]      Buffer        Value A pointer to the buffer to set.

  @return Return the pointer for the buffer been set.

**/
VOID*
EFIAPI
LibPcdSetPtr (
  IN      UINTN             TokenNumber,
  IN OUT  UINTN             *SizeOfBuffer,
  IN      VOID              *Buffer
  );


/**
  Sets the Boolean value for the token specified by TokenNumber 
  to the value specified by Value.  Value is returned.
  
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The boolean value to set.

  @return Return the value been set.

**/
BOOLEAN
EFIAPI
LibPcdSetBool (
  IN UINTN             TokenNumber,
  IN BOOLEAN           Value
  );


/**
  Sets the 8-bit value for the token specified by TokenNumber and 
  Guid to the value specified by Value. Value is returned.
  If Guid is NULL, then ASSERT().
  
  @param[in]  Guid          Pointer to a 128-bit unique value that 
                            designates which namespace to set a value from.
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 8-bit value to set.

  @return Return the value been set.

**/
UINT8
EFIAPI
LibPcdSetEx8 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber,
  IN UINT8             Value
  );


/**
  Sets the 16-bit value for the token specified by TokenNumber and 
  Guid to the value specified by Value. Value is returned.
  If Guid is NULL, then ASSERT().
  
  @param[in]  Guid          Pointer to a 128-bit unique value that 
                            designates which namespace to set a value from.
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 16-bit value to set.

  @return Return the value been set.

**/
UINT16
EFIAPI
LibPcdSetEx16 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber,
  IN UINT16            Value
  );


/**
  Sets the 32-bit value for the token specified by TokenNumber and 
  Guid to the value specified by Value. Value is returned.
  If Guid is NULL, then ASSERT().
  
  @param[in]  Guid          Pointer to a 128-bit unique value that 
                            designates which namespace to set a value from.
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 32-bit value to set.

  @return Return the value been set.

**/
UINT32
EFIAPI
LibPcdSetEx32 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber,
  IN UINT32            Value
  );


/**
  Sets the 64-bit value for the token specified by TokenNumber and 
  Guid to the value specified by Value. Value is returned.
  If Guid is NULL, then ASSERT().
  
  @param[in]  Guid          Pointer to a 128-bit unique value that 
                            designates which namespace to set a value from.
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The 64-bit value to set.

  @return Return the value been set.

**/
UINT64
EFIAPI
LibPcdSetEx64 (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber,
  IN UINT64            Value
  );


/**
  Sets a buffer for the token specified by TokenNumber to the value specified by 
  Buffer and SizeOfBuffer.  Buffer is returned.  If SizeOfBuffer is greater than 
  the maximum size support by TokenNumber, then set SizeOfBuffer to the maximum size 
  supported by TokenNumber and return NULL to indicate that the set operation 
  was not actually performed. 
  
  If Guid is NULL, then ASSERT().
  If SizeOfBuffer is NULL, then ASSERT().
  If SizeOfBuffer > 0 and Buffer is NULL, then ASSERT().
  
  @param[in]  Guid              Pointer to a 128-bit unique value that 
                                designates which namespace to set a value from.
  @param[in]  TokenNumber       The PCD token number to set a current value for.
  @param[in, out] SizeOfBuffer  The size, in bytes, of Buffer.
  @param[in]  Buffer            A pointer to the buffer to set.

  @return Return the pinter to the buffer been set.

**/
VOID *
EFIAPI
LibPcdSetExPtr (
  IN      CONST GUID        *Guid,
  IN      UINTN             TokenNumber,
  IN OUT  UINTN             *SizeOfBuffer,
  IN      VOID              *Buffer
  );


/**
  Sets the Boolean value for the token specified by TokenNumber and 
  Guid to the value specified by Value. Value is returned.
  If Guid is NULL, then ASSERT().
  
  @param[in]  Guid          Pointer to a 128-bit unique value that 
                            designates which namespace to set a value from.
  @param[in]  TokenNumber   The PCD token number to set a current value for.
  @param[in]  Value         The Boolean value to set.

  @return Return the value been set.

**/
BOOLEAN
EFIAPI
LibPcdSetExBool (
  IN CONST GUID        *Guid,
  IN UINTN             TokenNumber,
  IN BOOLEAN           Value
  );


/**
  When the token specified by TokenNumber and Guid is set, 
  then notification function specified by NotificationFunction is called.  
  If Guid is NULL, then the default token space is used. 
  If NotificationFunction is NULL, then ASSERT().

  This notification function serves two purposes. Firstly, it notifies the module which 
  did the registration that the value of this PCD token has been set. Secondly, 
  it provides a mechanism for the module which did the registration to intercept 
  the set operation and override the value been set if necessary. After the invocation 
  of the callback function, TokenData will be used by PCD service PEIM or driver to 
  modify the internal data in PCD database. 


  @param[in]      CallBackGuid    The PCD token GUID being set.
  @param[in]      CallBackToken   The PCD token number being set.
  @param[in, out] TokenData       A pointer to the token data being set.
  @param[in]      TokenDataSize   The size, in bytes, of the data being set.

**/
typedef
VOID
(EFIAPI *PCD_CALLBACK)(
  IN        CONST GUID        *CallBackGuid, OPTIONAL
  IN        UINTN             CallBackToken,
  IN  OUT   VOID              *TokenData,
  IN        UINTN             TokenDataSize
  );


/**
  When the token specified by TokenNumber and Guid is set, 
  then notification function specified by NotificationFunction is called.  
  If Guid is NULL, then the default token space is used. 
  If NotificationFunction is NULL, then ASSERT().

  @param[in]  Guid      Pointer to a 128-bit unique value that designates which 
                        namespace to set a value from.  If NULL, then the default 
                        token space is used.
  @param[in]  TokenNumber   The PCD token number to monitor.
  @param[in]  NotificationFunction  The function to call when the token 
                                    specified by Guid and TokenNumber is set.

**/
VOID
EFIAPI
LibPcdCallbackOnSet (
  IN CONST GUID               *Guid,       OPTIONAL
  IN UINTN                    TokenNumber,
  IN PCD_CALLBACK             NotificationFunction
  );


/**
  Disable a notification function that was established with LibPcdCallbackonSet().

  @param[in]  Guid          Specify the GUID token space.
  @param[in]  TokenNumber   Specify the token number.
  @param[in]  NotificationFunction The callback function to be unregistered.

**/
VOID
EFIAPI
LibPcdCancelCallback (
  IN CONST GUID               *Guid,       OPTIONAL
  IN UINTN                    TokenNumber,
  IN PCD_CALLBACK             NotificationFunction
  );


/**
  Retrieves the next PCD token number from the token space specified by Guid.  
  If Guid is NULL, then the default token space is used.  If TokenNumber is 0, 
  then the first token number is returned.  Otherwise, the token number that 
  follows TokenNumber in the token space is returned.  If TokenNumber is the last 
  token number in the token space, then 0 is returned.  If TokenNumber is not 0 and 
  is not in the token space specified by Guid, then ASSERT().

  @param[in]  Guid        Pointer to a 128-bit unique value that designates which namespace 
                          to set a value from.  If NULL, then the default token space is used.
  @param[in]  TokenNumber The previous PCD token number.  If 0, then retrieves the first PCD 
                          token number.

  @return The next valid token number.

**/
UINTN           
EFIAPI
LibPcdGetNextToken (
  IN CONST GUID               *Guid,       OPTIONAL
  IN UINTN                    TokenNumber
  );



/**
  Retrieves the next PCD token space from a token space specified by Guid.
  Guid of NULL is reserved to mark the default local token namespace on the current
  platform. If Guid is NULL, then the GUID of the first non-local token space of the 
  current platform is returned. If Guid is the last non-local token space, 
  then NULL is returned. 

  If Guid is not NULL and is not a valid token space in the current platform, then ASSERT().


  
  @param[in]  Guid  Pointer to a 128-bit unique value that designates from which namespace 
                    to start the search.

  @return The next valid token namespace.

**/
GUID *           
EFIAPI
LibPcdGetNextTokenSpace (
  IN CONST GUID  *Guid
  );


/**
  Sets the PCD entry specified by PatchVariable to the value specified by Buffer 
  and SizeOfBuffer.  Buffer is returned.  If SizeOfBuffer is greater than 
  MaximumDatumSize, then set SizeOfBuffer to MaximumDatumSize and return 
  NULL to indicate that the set operation was not actually performed.  
  If SizeOfBuffer is set to MAX_ADDRESS, then SizeOfBuffer must be set to 
  MaximumDatumSize and NULL must be returned.
  
  If PatchVariable is NULL, then ASSERT().
  If SizeOfBuffer is NULL, then ASSERT().
  If SizeOfBuffer > 0 and Buffer is NULL, then ASSERT().

  @param[in] PatchVariable      A pointer to the global variable in a module that is 
                                the target of the set operation.
  @param[in] MaximumDatumSize   The maximum size allowed for the PCD entry specified by PatchVariable.
  @param[in, out] SizeOfBuffer  A pointer to the size, in bytes, of Buffer.
  @param[in] Buffer             A pointer to the buffer to used to set the target variable.
  
  @return Return the pinter to the buffer been set.

**/
VOID *
EFIAPI
LibPatchPcdSetPtr (
  IN        VOID        *PatchVariable,
  IN        UINTN       MaximumDatumSize,
  IN OUT    UINTN       *SizeOfBuffer,
  IN CONST  VOID        *Buffer
  );

#endif
