## After 1 year I can say that [LinuxMint](https://linuxmint.com/) is a better option for a beginner
### Want to have a mac like experience in linux ?
Follow : https://www.youtube.com/watch?v=mFPDBruqmJQ

![lm2](https://raw.githubusercontent.com/arkapg211002/SEM-5-CSE/main/Operating%20Systems%20Lab%20(PCC-CS592)/All%20Assignments/lm2.png)


# Lab Assignments

[Operating System Lab Playlist](https://dextutor.com/courses/operating-system-programs/)

# Using Virtual Box is the easiest option 
After setting up the virtual machine, add windows drive to the shared folder, open the linux distro terminal, install the guest additions, `reboot` and run `sudo gpasswd -a <your username> vboxsf` to get access to the shared folder and `reboot`

# [Run Ubuntu GUI desktop in windows 10 without VirtualBox](https://gist.github.com/Ta180m/e1471413f62e3ed94e72001d42e77e22#file-wsl-2-gnome-desktop-md)

The options other than virtual memory and dual boot can slow down pc if not of high specs. Not sure of the reasons.

## Requirements:
 - WSL 2
 - Ubuntu 20.04 (other distros not tested)
 - An X server for Windows, such as [VcXsrv](https://sourceforge.net/projects/vcxsrv/)
 - Basic knowledege on how to run GUI apps with WSL 2 (not required but highly recommended)
## Getting ready

```sh
sudo apt update
sudo apt upgrade
```

Install GNOME: 

```sh
sudo apt install ubuntu-desktop gnome
```

Open up your `~/.bashrc`:

```sh
nano ~/.bashrc
```

And paste this in at the end and save:

```sh
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
export LIBGL_ALWAYS_INDIRECT=1
```

Enable `systemd`: 

```sh
git clone https://github.com/DamionGans/ubuntu-wsl2-systemd-script.git
cd ubuntu-wsl2-systemd-script/
bash ubuntu-wsl2-systemd-script.sh
```

Now shut down WSL 2: (run this in Windows)

```sh
wsl --shutdown
```

## Starting GNOME

Install [VcXsrv](https://sourceforge.net/projects/vcxsrv/)

First, fire up your X server on Windows. Make sure you let it through your firewall and disable access control.

Now, start up Ubuntu again and start GNOME:

```sh
gnome-session
```

If you don't get any error messages, you should be good. Wait a few seconds for GNOME to start up.

![Ubuntu 20.04 Desktop](https://raw.githubusercontent.com/arkapg211002/SEM-5-CSE/main/Operating%20Systems%20Lab%20(PCC-CS592)/All%20Assignments/Screenshot%20(41).png)

## Using Remote Desktop Connection (Another method)

Follow :- https://bwgjoseph.com/enhance-your-wsl-2-experience-with-xfce4
```
ifconfig | grep inet # to get the inet number to be inserted in RDC in windows
```

Looks like this

![Xfce4](https://raw.githubusercontent.com/arkapg211002/SEM-5-CSE/main/Operating%20Systems%20Lab%20(PCC-CS592)/All%20Assignments/Screenshot_2023-09-10_01-47-28.png)






