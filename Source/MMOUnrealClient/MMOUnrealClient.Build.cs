using UnrealBuildTool;

public class MMOUnrealClient : ModuleRules
{
	public MMOUnrealClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Networking",
            "Sockets",
            "AIModule", //Might be unused
            "NavigationSystem",
            "UMG",
            "Slate",
            "SlateCore",
            "MoviePlayer" // For loading screens
        });

		PrivateDependencyModuleNames.AddRange(new string[] {   });

        bEnableExceptions = true;

        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
