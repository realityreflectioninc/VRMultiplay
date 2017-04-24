using UnrealBuildTool;
using System.IO;

public class VRMultiplayPlugin : ModuleRules
{
    public VRMultiplayPlugin(TargetInfo Target)
    {
        PrivateIncludePaths.AddRange(new string[] { "VRMultiplayPlugin/Private", });
        PublicIncludePaths.AddRange(new string[] { "VRMultiplayPlugin/Public" });

        PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
    }
}