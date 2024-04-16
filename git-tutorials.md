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

<img src="figures/git-status.png" alt="git-status" style="zoom:70%;" />


将本地的`main`和远程的`origin/main`进行同步

查看所有分支：`git branch -a`，加上版本信息可以使用：`git branch -av`

`git fetch`只负责下载，不进行合并

## gitk和git gui

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

`gitk`也可以修改为英文界面：`alias gitk='LANG=en_GB gitk'`

刷新配置文件：`source ~/.bash_profile`

输入命令`git gui`可以打开GUI管理界main

## git refspec

`git config --global alias.xxx yyy` 对操作起一个别名

`git config --global alias.ui '!gitk'` 对外部命令添加别名， 执行`git ui`相当于执行`gitk`

创建对应远程分支的命令：`git checkout -b dev origin/dev`,  该操作在本地创建了分支`dev`，且追踪远程`orgin/dev`分支

本地分支建立追踪关系：`git push -u origin test`

设定远程分支追踪：`git checkout --track origin/test`

删除远程分支

方法1:`git push origin :dev`(将空分支推送到远程)

方法2:`git push origin --delete dev`

如果本地分支和远程分支名字不一样

```
git push --set-upstream --set-upstream origin dev:dev2
```

推送时需要使用命令：`git push origin HEAD:dev2`

或者使用：`git push origin dev:dev2`

本地和远程同名分支推送：`git push --set-upstream origin dev` (本地和远程分支名字都是dev)

`push`操作的完整命令：`git push origin src:dest`

`pull`操作的完整命令：`git pull origin src:dest`

`HEAD`指向当前所在分支的引用标识符，文件内部不包含`SHA-1`值，包含指向另一个引用的指针

执行`git commit`时，会创建一个`commit`对象，并且将这个对象的`parent`指针设置为`HEAD`所指向的`SHA-1`值

对于`HEAD`修改的操作会记录在`git reflog`中

`ORIG_HEAD`记录了远程`HEAD`的`SHA-1`

`FETCH_HEAD`记录了拉取代码

### 标签

`git push origin --tags`将本地所有标签推送到远程仓库

远程标签删除：`git push origin --delete tag <version>`

本地标签删除：`git tag -d <version>`

本地标签推送到远程（完整语法）：`git push origin refs/tags/<version>:refs/tags/<version>`

在缺省情况下，`refspec`会被`git remote add`命令自动生成，Git会获取远端上`refs/heads`下所有引用，并将他们写到本地的`refs/remote/origin`目录下

查看远程main分支的历史记录：

```
git log origin/main
git log remotes/origin/main
git log refs/remotes/origin/main
```

本地分支的信息存储在`.git/refs/heads`下

远程分支信息存储在`.git/refs/remotes`下

将远程main分支拉取到本地远程库的mymain分支下：

```
git fetch origin main:refs/remotes/origin/mymain
```

此时mymain分支处于stale状态，因为没有本地分支在track

建立追踪远程分支mymain的本地分支：

```
git checkout --track origin/mymain
```

## git gc

执行`git gc`可以将本地、远程、标签等信息压缩到`.git/packed-refs`中

远程仓库名字修改：

```
git remote rename origin origin2
```

删除远程仓库

```
git remote rm origin
```

重新添加回来

```
git remote add origin git@github.com:xxx.git
```

## 裸库和submodule

裸库是没有工作区的仓库，创建命令：`git init --bare`, 仅仅用来中转开发者的代码

建立测试Repo：`GitMain`和`GitSub`

将`GitSub`加入到`GitMain`的库中, 在`GitMain`端执行

```
git submodule add git@github.com:xxx/yyy.git <modulename>
```

`GitMain`中获取`GitSub`中的变化（已经推送到remote origin），进入`<modulename>`后执行`git pull`

一次性获取所有子库的更新：`git submodule foreach git pull`

新的开发者加入，执行`git clone`, 默认情况下不会`clone`子模块的代码

手动添加子模块

```
cd <modulename>
git submodule init # 注册子模块
git submodule update --recursive # 递归更新
```

或者执行参数拷贝：`git clone git@github.com:xxx/yyy.git <reponame> --recursive`

子模块删除

先从暂存区中删除：`git rm --cached <modulename>`

在本地执行`rm -rf <modulename> .gitmodules`

提交并推送

## Git Subtree

创建`SubTree`的主工程和子工程（使用默认主分支命名：`master`）

主工程中关联子工程：`git remote add subtree-origin <sub URL>`

添加依赖：`git subtree add --prefix=subtree subtree-origin master`

使用参数将多次提交合并：`git subtree add --prefix=subtree subtree-origin master --squash`

拉取子工程的更新：`git subtree pull --prefix=subtree subtree-origin master --squash`

等效命令：`git subtree pull -P subtree subtree-origin master --squash`

* 如果在添加子工程时使用了`--squash`参数，那么在`pull`操作的时候也需要使用`--squash`参数，相关issue参见[fatal refusing in subtree](https://stackoverflow.com/questions/39281079/git-subtree-error-fatal-refusing-to-merge-unrelated-histories)，git合并执行的原则为"三方合并"，如果在开始使用了`--squash`参数，后面的步骤都需要使用`--squash`参数。

在主工程中更新`<submodule>`中的内容，然后推回到子工程中

1. 在`subtree/<filename>`进行文件内容修改
2. 推送到远程仓库
3. 推送到子工程：`git subtree push -P subtree subtree-origin master`
4. 子工程从远程仓库中拉取更新

功能模块提取，使用`split`

## Git cherry-pick & Rebase

将某个分支的修改应用到其他分支上：`git cherry-pick <commit_id>`

变基、衍合：`rebase`, 功能类似于`merge`, 改变分支的根基

```
git checkout <work>
git rebase <origin>
```

会修改git的提交list

- rebase过程中也会出现冲突
- 冲突解决后，使用`git add`添加，然后执行：`git rebase --continue`
- rebase操作可以在任何时候被终止，分支会恢复到rebase开始前的状态，`git rebase --abort`

- 一般不会对master分支执行rebase操作，容易引发问题
- rebase一般应用在本地分支，没有推送到远程仓库

在本地建立repo，设置两个分支`test`和`dev`

在dev分支执行rebase操作，test分支的内容将以patch的形式发布到dev分支，整个流程将会**变成一条直线**

执行`git rebase --abort`丢弃变基操作

rebase遇到冲突的时候，可以进行手动解决，然后使用`git rebase --continue`继续执行变基操作

也可以使用`git rebase --skip`跳过patch

























