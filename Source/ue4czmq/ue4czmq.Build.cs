// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
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

            // CZMQ
            string czmqPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/", Target.Platform.ToString(), "czmq"));
            PublicAdditionalLibraries.Add(Path.Combine(czmqPath, "Libraries", "czmq.lib"));
            PrivateIncludePaths.Add(Path.Combine(czmqPath, "Includes"));

            // LIBZMQ
            string libzmqPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/", Target.Platform.ToString(), "libzmq"));
            PrivateIncludePaths.Add(Path.Combine(libzmqPath, "Includes"));
        }
	}
}