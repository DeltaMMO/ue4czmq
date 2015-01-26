# ue4czmq
CZMQ bindings with UE4

## Installation

Put ue4czmq at the following path:
**Your project**/Plugins/ue4czmq

Create the third party folder for your architecture at:
**Your project**/Plugins/ue4czmq/ThirdParty/**Architecture**

In there, create a folder for czmq and libzmq

The czmq folder should contain Includes and Libraries subfolders with the includes and the needed lib file respectively.
The libzmq folder should contain an Includes folder with the libzmq headers.

If libsodium, libzmq or czmq were compiled as a DLL, the DLL should be placed in the **Your Project**/Binaries/**Architecture** folder

## Precompiled third party headers
Precompiled versions of the needed libraries of select Platforms can be found at https://drive.google.com/folderview?id=0ByVeBij1wH9Vd3NSTUx5YU1XdjQ&usp=sharing

Place the ThirdParty folder in the archive in **Your project**/Plugins/ue4czmq/ and the DLLs in the root at **Your Project**/Binaries/**Architecture**
