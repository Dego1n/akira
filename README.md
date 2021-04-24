# Game client

# Cloning project
If you are using linux you need to install git-lfs with something like: `apt install git-lfs`.

*Git-for-windows seems to have it out of the box, so you don't need to install anything.*

Now install git lfs localy before cloning the repo with this command: `git lfs install --skip-repo`

And finally you can `git clone` this repository.

After cloning process will be done, git-lfs will start to download large binaries from remote server. Git will ask you for http basic auth. You can find credentials in a confluence.

If there are errors during lfs pull process then you need to repeat `git lfs fetch` and `git lfs checkout` until errors are gone.
After all of this make sure you are on develop branch (`git checkout -f develop`) because after errors during clone your files might be untracked.

# Required software
* Unreal Engine 4.26
* Visual studio 2019

Visual studio packages:
* C++ Classic programs development
* C++ Game game development
* .NET Framework 4.5 - 4.8 and SDK for .NET Framework 4.6.1, 4.6.2 (//TODO: Update which is actually required)

It is recomended to only have English language pack for visual studio, because errors thrown are not suporting other encoding

# Opening project
Start Unreal Engine (Current version for this project is 4.26)![image](https://user-images.githubusercontent.com/12961898/115968773-15607680-a542-11eb-9c21-61771b212b37.png)

Go to `More`, press `Browse`, navigate to a project folder and select `*.project` file.



# Troubleshooting
* "error C3859: virtual memory range for PCH exceeded" during compiling source code

This happens when your system is out of space. Keep in mind that visual studio might take space on a drive that does not contain project source code.
