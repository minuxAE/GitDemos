# 简易案例

版本库创建命令：`git init`

将`~/minux_programs/Git/Demos`作为实验库

配置信息文件`.gitconfig`

编写测试文件`random.c`

将文件添加到版本库中`git add random.c`

向服务端提交代码文件: `git commit -a -m "xxx"`

`-m`表示添加注释信息

`-a`表示接受被追踪文件的所有变更

发布项目：`git push`

## 基本命令

`git checkout -- <filename>`： 放弃文件的修改

`git status`：查看缓存区文件的状态（工作空间）

`git reset HEAD <file>`：放弃修改

`git commit -m 'XXX'`：提交修改

配置`git`参数：`git config --local user.name`以及`git config --local user.email`

也可以指定为`global`

`git rm`：删除文件，并将被删除文件纳入暂存区

如果需要恢复被删除的文件，需要执行两个动作：

1. `git reset HEAD <file>` 将待删除文件从暂存区恢复到工作区
2. `git checkout -- <file>` 将工作区中的修改丢弃掉

`git commit --amend -m 'message'` 修正上次提交的message

# .gitignore和分支

分支删除：`git branch -d <branchname>` , 需要切换到别的分支上再进行删除

`git checkout -b new_branch`创建新分支并切换到该分支上

# 分支进阶与版本回退

`HEAD`指向的是当前分支，`main`指向提交

如果可能，合并分支会使用`fast-forward`模式

如果加上参数`--no-off`参数会禁用`fast-forward`，这样会多出一个`commit id`

```
git merge --no-ff dev
git log --graph # 图形化方式查看提交
```

`git commit -am 'comments'`相当于添加并且提交

`git log --graph --abbrev-commit` 信息为缩写

`git long --graph --pretty=oneline --abbrev-commit` 信息缩写到一行表示

### Git版本回退

以下命令可以实现到回退到上一个提交

`git reset --hard HEAD^`

`git reset --hard HEAD~1` 回到第一个提交

`git reset --hard commit_id`

操作日志：`git reflog`

# Checkout进阶和Stash

`git checkout -- <file>`丢弃当前文件的修改，返回到暂存区中的版本

`git restore <file>`等效

`git reset HEAD <file>` 从暂存区中取消暂存，移动到工作区

`git checkout`切换到分支的最新提交点，也可以回到旧的提交点，例如`git checkout 937f3`

`git stash`将当前的分支的修改临时保存起来

`git stash list`查看所有的保存状态

`git stash pop`将临时状态恢复并从列表中删除

`git stash apply`将临时状态恢复但是不从列表中删除该状态

`git stash drop stash@{0}` 删除之前保存的状态

`git stash apply stash@{1}`恢复之前保存的状态

# 标签与diff

标签有两种：轻量级标签（lightweight）和带有附注的标签（annotated）

创建一个轻量级标签：`git tag v1.0.1`

创建一个带有附注的标签：`git tag -a v1.0.2 -m 'release version'`

删除标签：`git tag -d <tag_name>`

## git blame

查看文件修改信息：`git blame <file>`

## git diff

比较暂存区和工作区文件的差别

`git diff HEAD` 比较工作区与最新提交的差别

`git diff --cached commit_id` 暂存区和最新的提交的之间的差别

# 远程和Github

`pull = fetch + merge`, 拉取，同时会执行`merge`

`GitLab`内网搭建所用

# Git应用开发

基于Git分支开发模型：

1.`develop`分支（频繁变化的分支）

2.`test`分支（测试分支，变化不是很频繁）

3.`main`分支（发布分支）

4.`bugfix`分支（热备份、修复分支）

