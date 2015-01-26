# ue4czmq
CZMQ bindings with UE4

# Installation

Put ue4czmq at the following path:
_Your project_/Plugins/ue4czmq

Create the third party folder for your architecture at:
_Your project_/Plugins/ue4czmq/ThirdParty/_Architecture_

In there, create a folder for czmq and libzmq

The czmq folder should contain Includes and Libraries subfolders with the includes and the needed lib files / dlls respectively (depending on how you compiled libzmq/czmq/libsodium)
The libzmq folder should contain an Includes folder with the libzmq headers

Precompiled versions of the needed libraries of select Platforms can be found at https://drive.google.com/folderview?id=0ByVeBij1wH9Vd3NSTUx5YU1XdjQ&usp=sharing
