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

<img src="/Users/minux/Desktop/minux_programs/Git/GitDemos/figures/git-status.png" alt="git-status" style="zoom:50%;" />


将本地的`main`和远程的`origin/main`进行同步

查看所有分支：`git branch -a`

