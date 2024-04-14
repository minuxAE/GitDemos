# Git Tutorials

查看系统的环境变量：`echo $PATH`

查看git的版本：`git --version`

## Git 协作

本地库可以对应多个远程库

查看关联的远程库：`git remote show`

查看指定的远程库：`git remote show origin`

```
...
HEAD branch: main
  Remote branches:
    better_random tracked
    main          tracked
    test_branch   tracked
  Local branch configured for 'git pull':
    main merges with remote main
  Local ref configured for 'git push':
    main pushes to main (up to date)
```

远程推送：`git push`

<img src="figures/git-status.png" alt="git-status" style="zoom:50%;" />


将本地的`main`和远程的`origin/main`进行同步

查看所有分支：`git branch -a`，加上版本信息可以使用：`git branch -av`

`git fetch`只负责下载，不进行合并

## gitk和git GUI

MAC机器在默认`Xcode`中提供的`git`没有安装`gitk`, 需要更换为`homebrew`中安装的`git`

1.更新`homebrew`: `brew update`

2.安装`git`:`brew install git`

3.安装`gitk`: `brew install git-gui`

4.国内安装走的是清华镜像，`zsh`界面变成了中文，可以通过修改`~/.bash_profile`文件调整

```
export GIT=/opt/homebrew/bin/git # 将GIT定位到homebrew安装的
alias git='LANG=en_GB git' # 英文界面
```

使用命令`gitk`可以开启MAC中的GUI

![gitk](figures/gitk.png)



