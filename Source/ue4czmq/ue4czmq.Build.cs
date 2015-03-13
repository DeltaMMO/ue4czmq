// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ue4czmq : ModuleRules
{
    public ue4czmq(TargetInfo Target)
	{
        // Include paths
        //PublicIncludePaths.AddRange(new string[] {});
        //PrivateIncludePaths.AddRange(new string[] {});

        // Dependencies
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "Engine", "CoreUObject" });
            
        //PrivateDependencyModuleNames.AddRange(new string[] {});

        // Dynamically loaded modules
        //DynamicallyLoadedModuleNames.AddRange(new string[] {});

        // Definitions
        Definitions.Add("WITH_UE4CZMQ=1");

        LoadLib(Target);
	}

    public void LoadLib(TargetInfo Target)
    {
        string ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
        string extension = UEBuildPlatform.GetBuildPlatform(Target.Platform).GetBinaryExtension(UEBuildBinaryType.StaticLibrary);

        // CZMQ
        string czmqPath = Path.GetFullPath(Path.Combine(ModulePath, "../../../../ThirdParty/", Target.Platform.ToString(), "czmq"));
        PublicAdditionalLibraries.Add(Path.Combine(czmqPath, "Libraries", "czmq" + extension));
        PrivateIncludePaths.Add(Path.Combine(czmqPath, "Includes"));

        // LIBZMQ
        string libzmqPath = Path.GetFullPath(Path.Combine(ModulePath, "../../../../ThirdParty/", Target.Platform.ToString(), "libzmq"));
        if (Directory.Exists(Path.Combine(libzmqPath, "Libraries")))
        {
            PublicAdditionalLibraries.Add(Path.Combine(libzmqPath, "Libraries", "libzmq" + extension));
        }
        PrivateIncludePaths.Add(Path.Combine(libzmqPath, "Includes"));

        // Libsodium
        string libsodiumPath = Path.GetFullPath(Path.Combine(ModulePath, "../../../../ThirdParty/", Target.Platform.ToString(), "libsodium"));
        if (Directory.Exists(Path.Combine(libsodiumPath, "Libraries")))
        {
            PublicAdditionalLibraries.Add(Path.Combine(libsodiumPath, "Libraries", "libsodium" + extension));
        }
    }
}