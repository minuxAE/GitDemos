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

`git reset --hard HEAD~1`

`git reset --hard commit_id`

返回到某一个版本：`git reflog`