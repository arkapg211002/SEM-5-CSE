# Assignments

# Run Ubuntu GUI desktop in windows 10 without VirtualBox
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






