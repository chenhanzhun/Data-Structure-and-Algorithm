从远端下载

$ git clone <remote url> (<local_dir>)
显示远端URL

$ git remote -v
向远端推送

$ git push (-f) <remote name>
重置到之前的某个版本

$ git reset HEAD~1
增加一个远端

$ git remote add <remote name> <remote url>
删除一个远端

$ git remote rm <remote name>
$ git remote remove <remote name>
重命名远端

$ git remote rename origin github
从git仓库中取出一个文件

$ git checkout <file name>
从远端获取最新文件

$ git fetch <remote name>
merge从远端获取的文件

$ git merge <remote name>/<remote branch>
从index区中删除某个文件

$ git rm --cached <file to be rm>
显示log，一次提交占一行

$ git log --pretty=oneline
查看最后一次更改的细节

$ git log -p -1
启动gitk

$ gitk
查看这次更改的详细内容

$ git log -p
查看上一次更改

$ git log -1
查看git配置信息

$ git config --list
将本地git仓库推送到远端

$ git push -u origin master
设置用户名

$ git config --global user.name <your name here>
显示远端信息

$ git remote show <remote name>
切换到某个分支

$ git branch <branch name>
将某个分支merge到当前分支

$ git merge <branch-name>
将本地的所有分支都push到远端

$ git push <remote-name> --all
让git停止追踪某个文件

$ git rm --cached .project
查看分支信息

$ git branch -v
创建一个新分支并切换到该分支

$ git checkout -b <branch-name>
删除某个分支

$ git branch -d(D) <branch_name>
列出没有被merge的分支

$ git branch --no-merged
列出已经merge好了的分支

$ git branch --merged
修改最近一次提交

$ git commit --amend
提交一个tag

$ git tag -a <tag-name>
列出所有被删除了的文件

$ git ls-files deleted
更新index目录（添加或删除了文件）

$ git add -u
从git仓库中取出一个文件, 替换掉本地改动

$ git checkout -- app/res/values/strings.xml
unstage某个文件（从index区移除）

$ git reset HEAD <file>
显示某个标签

$ git show <tag-name>
显示某个标签的详细信息

$ git tag -v <tag-name>
为某次提交添加一个tag

$ git tag -a <tag-name> <commit-id>
将某个tag推送到远端

$ git push <remote-name> <tag-name>
将所有tag都推送到远端

$ git push <remote-name> --tags
显示所有新添加的文件

$ git status -u
删除所有尚未被git追踪的新添加的文件

$ git clean -df
放弃尚未commit的所有修改

$ git checkout -- .
显示上次commit对某个文件做的修改细节

$ git log -p -1 <file-name>
使用gitk工具查看某个文件

$ gitk .gitignore
Your branch and 'origin/master' have diverged,

$ git log HEAD..origin/master
$ git merge origin/master
unstaging a staged file

$ git reset HEAD <file>
放弃对某个文件的修改

$ git checkout -- <file>
在commit之前显示修改细节

$ git commit -v
删除log文件夹下所有以log为后缀的文件

$ git rm log/\*.log
删除所有以~为后缀的文件

$ git rm \*~
重命名某个文件

$ git mv <old-name> <new-name>
reset至前一次提交时的版本

$ git reset HEAD~1
push并且update

$ git push -u origin master
删除远端某个分支

$ git push <remote-name> :<branch-name>
重命名某个远端

$ git remote rename <old-name> <new-name>
列出某个程序员的所有提交

$ git log --author=<author-name or email>
列出某个提交者的所有提交

$ git log --committer=<committer-name or email>
获取某个文件之前的版本

$ git checkout HEAD~1 <file-name>
直接从git仓库检出某个文件（跳过缓存区）

$ git checkout HEAD 文件名
查看某个文件在上次提交时的样子

$ git show HEAD~1:<file-name>
unstage 所有文件

$ git rm --cached .
git add . & git add -u

$ git add -A
彻底从git仓库中移除某个文件

$ git filter-branch --index-filter 'git rm --cached --ignore-unmatch <full path of this file here>' \
--prune-empty --tag-name-filter cat -- --all
$ rm -rf .git/refs/original/
$ git reflog expire --expire=now --all
$ git gc --prune=now
$ git gc --aggressive --prune=now
显示所有git正在追踪的文件

$ git ls-files
在7200秒(2个小时)内记住密码

$ git config --global credential.helper 'cache --timeout=7200'
忘记之前缓存的密码

$ git config --system --unset-all credential.helper
merge project pro_x into project pro_main

$ git remote add <pro_x name> <remote url of pro_b>
$ git fetch <pro_x name>
$ git merge <pro_x name>/<pro_x branch name>
deal with conflict files manually
$ git remote remove <pro_x name>
显示上次提交更新的文件

$ git diff --name-only HEAD^ HEAD
显示某个文件在工作区和缓存区的差别

$ git diff <file-path-goes-here>
显示某个文件在缓存区和git仓库的差别

$ git diff --cached <file-path-goes-here>
显示改动过某个文件的所有提交

$ git log --follow <file-name>
显示上次提交改动了什么文件

$ git whatchanged -1
显示HEAD履历信息

$ git reflog
将最近三次提交打成patch

$ git format-patch -3
生成某两次提交之间的patch

$ git format-patch HEAD@{1}..HEAD
merge某个patch

$ git apply <patch-file-name>
回退上次提交

$ git revert HEAD
查看所有提交

$ git shortlog
为某次提交补加一个tag

$ git tag -a <tag-name> <commit> -m 'messag-here'
清理垃圾

$ git gc
显示两次提交中有差别的文件

$ git diff --name-only <commit> <commit>
取出某个文件在某次提交时的版本

$ git checkout <commit> <file>
显示某个文件在两次提交中的差别

$ git diff <commit> <commit> <file>
显示配置信息

$ git config -l
比较工作去和缓存区的差别

$ git diff
比较缓存区和上次提交的差别

$ git diff --cached
比较当前工作区中内容和上次提交时的差别

$ git diff HEAD
显示HEAD之前的第6次提交同HEAD之前的第2次提交之间的差别

$ git diff HEAD~6..HEAD~2
显示那些包含“update”字符串的log

$ git log --grep=update
显示那些包含“update”字符串的log

$ git log --since=2013-03-22
根据远端仓库进行重置

$ git reset origin/HEAD
删除本地tag

$ git tag -d <tag-name>
重命名某个分支

$ git branch -m <old-name> <new-name>
设置默认编辑器

$ git config --global core.editor vim
重置本次merge（当merge失败时）

$ git reset --merge
强制推送至远端，即使存在冲突、没merge好

$ git push origin --force master 
第一次向远端推送

$ git push -u origin --all   # to push up the repo for the first time
初始化一个远程仓库

$ mkdir <project name>
$ cd <project name>
$ mkdir .git
$ cd .git/
$ git --bare init
比较当前工作区与上次提交之间的差别

$ git diff HEAD
使用HEAD重置所有文件

$ git reset (--hard)
放弃本地改动&提交，获取远端服务器最新版本

$ git fetch origin
$ git reset --hard origin/master
使用HEAD重置某个文件

$ git reset -- <file-name>
查看上次commit做了哪些修改

$ git diff HEAD^^
匹配以@开头，以#结尾的字符串（如：“@abc#”）

$ @.*#
删除标签

$ git tag -d v1.16.6
推送所有分支

$ git push origin --all
启动图形化merge工具

$ git mergetool
让git忘记某个文件

$ git rm <file-name>
让git忘记某个文件夹

$ git rm -r <folder-name>/
重命名某个文件

$ git mv <old-name> <new-name>
撤销某次提交

$ git revert <commit-hash> 
查看自昨天的改动细节

$ git diff '@{yesterday}'
查看两天内的提交记录

$ git whatchanged --since='2 days ago'
列出包含"featured"的标签

$ git tag -l '*featured*'
列出在某次commit中所修改的所有文件

$ git show --name-only <commit-hash>
列出修改了某个文件的所有commit

$ git log -p <file-name>
列出两个commit之间变化了的文件

$ git diff --name-only <hash-1> <hash-2>
遇到以下错误

$ git status
error: bad index file sha1 signature
fatal: index file corrupt
解决方案：
1. 备份
2. rm -f .git/index
3. git reset
merge错误：

fatal: You have not concluded your merge (MERGE_HEAD exists). Please, commit your changes before you can merge. 解决方案： $ git reset --merge

缓存(隐藏)变更

$ git stash
查看所有缓存变更列表

$ git stash list
应用缓存的变更

$ git stash apply
应用缓存的变更后将其从缓存栈中取走

$ git stash pop
撤销git add <file>

$ git reset <file>
在将dev分支merge都master分支时，保留一个节点

$ git merge --no-ff dev
查看hash对应的内容

$ git cat-file -p <hash>
查看每次提交文件变化（增、删行数）

$ git log --stat
查看HEAD中的目录树

$ git ls-tree HEAD
打印文件内容

$ git cat-file -p
工作区和HEAD比较

$ git diff HEAD
一行显示log

$ git log --oneline
重置暂存区，即，undo 'git add' 命令

$ git reset HEAD
查看总提交次数

$ git rev-list HEAD | wc -l
显示中文文件名(而非Unicode)

$ git config --global core.quotepath false
删除设置

$ git config --unset --global user.name
修改提交者

$ git commit --amend --author='name'
查看某一文件的修改记录

$ git blame 文件名
基于master分支，将dev分支的零散提交合并起来

$ git rebase -i master
在向推送前整合提交

$ git rebase -i origin/master
安装tig

$ sudo apt-get install tig
询问式add, checkout, reset

$ git add -i
$ git checkout -p
$ git reset -p
Problem:

fatal: You have not concluded your merge (MERGE_HEAD exists).
Please, commit your changes before you can merge.
Solution-1:
$ rm -rf .git/MERGE*
Solution-2:
$ git reset --merge
修改上次提交的作者信息

$ git commit --amend --author="name <email>"
