# Отчет по лабораторной работе №1

# ЭТАП 1
### Установка и настройка

**Команды:**
git --version    

**результат**
````bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ git version
git version 2.53.0.windows.1
````
**Описание:**
Эта команда показывает версию Git, установленную на моем ноутбуке. Версия 2.53.0 подтверждает, что Git правильно установлен.

````bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ git config --global user.name "Judy Banda"

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ git config --global user.email "judybanda19@gmail.com"
````
**Описание:**
--global означает, что это применяется ко всем вашим репозиториям на этом компьютере, а не только к одному проекту.

user.name — ваше имя, которое отображается в каждом коммите.

user.email — ваша электронная почта, которая отображается в каждом коммите.

Выполнение команды `git config --global user.name "Ваше имя"`
настраивает идентификатор пользователя. Это необходимо, поскольку каждый коммит **Git** использует эту информацию для идентификации автора изменений.

$ git --help


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ git --help
usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--no-lazy-fetch]
           [--no-optional-locks] [--no-advice] [--bare] [--git-dir=<path>]
           [--work-tree=<path>] [--namespace=<name>] [--config-env=<name>=<envvar>]
           <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add        Add file contents to the index
   mv         Move or rename a file, a directory, or a symlink
   restore    Restore working tree files
   rm         Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   diff       Show changes between commits, commit and working tree, etc
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

grow, mark and tweak your common history
   backfill   Download missing objects in a partial clone
   branch     List, create, or delete branches
   commit     Record changes to the repository
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   reset      Set `HEAD` or the index to a known state
   switch     Switch branches
   tag        Create, list, delete or verify tags

collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.
See 'git help git' for an overview of the system.

`git --help`. Это встроенная шпаргалка **Git**. Она показывает список наиболее важных команд, которые программист использует каждый день.Она поможет вам быстро вспомнить, как начать работу, сохранить изменения, работать онлайн.

источник [git](https://git-scm.com/docs)

# ЭТАП 2

### Начало работы с новым проектом

**Команды:**

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ mkdir Git-labs

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ cd Git-labs

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ touch README.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ mkdir reports

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ touch reports/lab1.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ ls
README.md  reports/

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ cd reports

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/reports
$ ls
lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/reports
$ start reports/lab1.mds
```

Команда `mkdir Git-labs` создаёт новую папку с именем Git-labs, cd Git-labs переходит в эту папку, `touch README.md` создаёт пустой файл README.md, `mkdir reports` создаёт папку reports, `touch reports/lab1.md` создаёт пустой файл lab1.md внутри папки reports, ls показывает файлы и папки в текущем каталоге, cd reports переходит в папку reports, а `ls` отображает содержимое этой папки.

Markdown — это простой язык форматирования, используемый для написания и форматирования текста с помощью обычных текстовых символов, часто для таких документов, как файлы README, отчеты и документация.

- Заголовки: подойти с помощью решетки `#` (чем больше решеток, тем меньше заголовок).
- Списки: обычные пункты через дефис `-` или звездочку `*`, нумерованные — через цифру с точкой 1..
- Выделение: `**жирный текст**` и `*курсив*`.
- Код: одна обратная кавычка (`) для отображения команды внутри строк и три кавычки (```) для целых блоков кода.
- Ссылки: текст пишется в квадратных скобках, ссылка — в круглых сразу за ними: `[Текст](ссылка)`.

источник [Markdown Guide](https://www.markdownguide.org/)

# ЭТАП 3
### Отслеживание состояния кода

**Команды:**
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs
$ git init
Initialized empty Git repository in C:/Users/Judy Banda/Git-labs/.git/

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md
        reports/

nothing added to commit but untracked files present (use "git add" to track)

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git diff

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ 
```

**Описание:**
Команда `git status` показывает текущее состояние репозитория,
указывая на то, что мы находимся в ветке `main` без каких-либо коммитов,
и что файлы `README.md` и `reports/` являются неотслеживаемыми файлами,
которые Git видит, но пока не отслеживает.

Команда `git diff` показывает изменения, внесенные в уже отслеживаемые файлы,
но не выдает никакого результата, поскольку файлы README.md и reports/
на этом этапе еще не отслеживались.

**Команды:**
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git add .
```
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
        new file:   reports/lab1.md
```

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git diff --cached reports/lab1.md
```
diff --git a/reports/lab1.md b/reports/lab1.md
new file mode 100644
index 0000000..8a69538
--- /dev/null
+++ b/reports/lab1.md
@@ -0,0 +1,163 @@
+# Отчет по лабораторной работе №1
+
+ЭТАП 1
+### Установка и настройка
+
+**Команды:**
+git --version
+
+**результат**
+````bash
+Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
+$ git version
+git version 2.53.0.windows.1
+````
+**Описание:**
+Эта команда показывает версию Git, установленную на моем ноутбуке. Версия 2.53.0 подтверждает, что Git правильно установлен.
+
+````bash
+Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
+$ git config --global user.name "Judy Banda"
+
+Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
+$ git config --global user.email "judybanda19@gmail.com"
+````
+**Описание:**
+--global означает, что это применяется ко всем вашим репозиториям на этом компьютере, а не только к одному проекту.
+
+user.name — ваше имя, которое отображается в каждом коммите.
+
+user.email — ваша электронная почта, которая отображается в каждом коммите.
+
+$ git --help
+
+
+Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
+$ git --help
+usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
+           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
+           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--no-lazy-fetch]
+           [--no-optional-locks] [--no-advice] [--bare] [--git-dir=<path>]
+           [--work-tree=<path>] [--namespace=<name>] [--config-env=<name>=<envvar>]
+           <command> [<args>]
+
+These are common Git commands used in various situations:
+
+start a working area (see also: git help tutorial)
+   clone      Clone a repository into a new directory
+   init       Create an empty Git repository or reinitialize an existing one
+
+work on the current change (see also: git help everyday)
+   add        Add file contents to the index
+   mv         Move or rename a file, a directory, or a symlink
+   restore    Restore working tree files
+   rm         Remove files from the working tree and from the index
+

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git diff README.md
```

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git diff --cached README.md
diff --git a/README.md b/README.md
new file mode 100644
index 0000000..bbecb77
--- /dev/null
+++ b/README.md
@@ -0,0 +1,7 @@
+# Лабораторная работа №1
+## Тема:Базовая работа с git.
+
+ Дисциплина:Основы разработки программного обеспечения.
+ Студент выполнениe:Джуди Банда
+ Группа: 5130201/50001
+ Date: 12/03/2026
\ No newline at end of file
```


Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
        new file:   reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git rm --cached README.md
rm 'README.md'

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git commit -m "commit reports/lab1.md"
[main (root-commit) 303db03] commit reports/lab1.md
 1 file changed, 267 insertions(+)
 create mode 100644 reports/lab1.md




# ЭТАП 4

### Откат изменений

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status

On branch main
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

no changes added to commit (use "git add" and/or "git commit -a")


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status

On branch main
nothing to commit, working tree clean


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ cp reports/lab1.md reports/lab1_backup.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ rm reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status

On branch main
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    reports/lab1.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        reports/lab1_backup.md

no changes added to commit (use "git add" and/or "git commit -a")


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git restore reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status

On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        reports/lab1_backup.md

nothing added to commit but untracked files present (use "git add" to track)
```
 Команда `git restore README.md` возвращает файл к состоянию последнего коммита, удаляя все внесённые изменения. По сути, это откатывает файл так, как будто никакие новые строки или правки никогда не добавлялись, похоже на использование Отменить (Ctrl+Z) для всего документа сразу.
  
  Я сохранила изменения перед восстановлением, в результате чего потеряла обновленный отчет.

# ЭТАП 5

### Ветвление версий
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git branch
* main

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git checkout -b lab1-1
Switched to a new branch 'lab1-1'

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git branch
* lab1-1
  main
```
Когда вы переключаетесь обратно на основную ветку (main), все изменения, сделанные в ветке lab1-1, не переносятся — файлы, например lab1.md, остаются такими, какими они были в последнем коммите на основной ветке.

Если вы внесли изменения в файл README.md в основной ветке, но не добавили их в индекс и не закоммитили, эти изменения будут "следовать" за вами при переключении ветки, но пока они не добавлены или не зафиксированы, они остаются только в рабочей копии.


`git branch` показывает все ветки репозитория, где символ * указывает 
на текущую активную ветку, и в выводе была показана только ветка * main.

`git checkout -b lab1-1` создала новую ветку lab1-1 и автоматически 
переключилась на неё, вывод показал: Switched to a new branch 'lab1-1'.

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git add reports/lab1.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git commit -m " add branching notes"
[lab1-1 af43e9a]  add branching notes
 1 file changed, 103 insertions(+), 14 deletions(-)
```

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        reports/README.md
        reports/lab1_backup.md
```
Когда я переключаюсь на ветку lab1-1, файл README.md, который ещё не добавлен в Git (untracked), переносится вместе со мной в новую ветку. Это происходит потому, что Git не отслеживает такие файлы и не привязывает их к конкретной ветке, поэтому они остаются в рабочей директории независимо от того, на какой ветке я нахожусь.


# ЭТАП 6
### Слияние веток, конфликты
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git add README.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git status
On branch lab1-1
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   README.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git restore --staged README.md
bash: $'\302\223git': command not found

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git restore --staged README.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git status
On branch lab1-1
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

no changes added to commit (use "git add" and/or "git commit -a")

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git checkout main
error: Your local changes to the following files would be overwritten by checkout:
        reports/lab1.md
Please commit your changes or stash them before you switch branches.
Aborting
```
Я использовала `git stash` чтобы временно отложить незавершённые 
изменения в файле `reports/lab1.md`, свободно переключиться на ветку 
`main` для слияния, а затем восстановила изменения с помощью 
`git stash pop` там, где я остановилась.

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git stash
Saved working directory and index state WIP on lab1-1: a878f08  new changes

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git checkout main
Switched to branch 'main'

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git merge lab1-1
Updating 641a059..a878f08
Fast-forward
 reports/lab1.md | 131 ++++++++++++++++++++++++++++++++++++++++++++++++++------
 1 file changed, 117 insertions(+), 14 deletions(-)

 Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git log --oneline
a878f08 (HEAD -> main, lab1-1)  new changes
af43e9a  add branching notes
641a059 updated lab1
303db03 commit reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git add README.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   README.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git commit -m "Update README title"
[main a27827c] Update README title
 1 file changed, 10 insertions(+)
 create mode 100644 README.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git checkout lab1-1
Switched to branch 'lab1-1'

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git stash pop
On branch lab1-1
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (77a9b69f8e846b3c236f87c02163e8f3440c8535)

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab1-1)
$ git status
On branch lab1-1
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md

no changes added to commit (use "git add" and/or "git commit -a")

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main|MERGING)
$ git commit -m "Resolving merge conflct in README
> git commit -m "Resolving merge conflict in README"
> $ git commit -m Resolving merge conflict in README"
fatal: cannot do a partial commit during a merge.

```

 **Решение:**

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main|MERGING)
$ git commit -m "Resolving merge conflict in README"
[main afcea04] Resolving merge conflict in README

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main
nothing to commit, working tree clean

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git log --online
fatal: unrecognized argument: --online

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git log --oneline
afcea04 (HEAD -> main) Resolving merge conflict in README
47e8740 (lab1-1) Upated and report and README in lab1-1
a27827c Update README title
a878f08  new changes
af43e9a  add branching notes
641a059 updated lab1
303db03 commit reports/lab1.md

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git branch -d lab1-1
bash: $'\302\223git': command not found

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git branch -d lab1-1
Deleted branch lab1-1 (was 47e8740).

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git branch
* main
```
Я разрешила конфликты в файле README.md, сохранил нужные изменения, добавил файл в индекс и сделал коммит, чтобы завершить слияние. После того как убедился, что все изменения из ветки lab1-1 были включены в main, я удалил ветку lab1-1 с помощью команды `git branch -d lab1-1.`


# ЭТАП 7
### Работа с удаленным репозиторием
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git remote add origin https://github.com/judy-tapioca/Git-labs.git

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git branch M main

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git push -u origin main
Enumerating objects: 27, done.
Counting objects: 100% (27/27), done.
Delta compression using up to 12 threads
Compressing objects: 100% (18/18), done.
Writing objects: 100% (27/27), 7.73 KiB | 494.00 KiB/s, done.
Total 27 (delta 7), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (7/7), done.
To https://github.com/judy-tapioca/Git-labs.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.

```
# ЭТАП 8
### Синхронизация с удаленным репозиторием

 Клонирование в Git — это создание полной копии удалённого репозитория на локальном компьютере с помощью команды `git clone`. При клонировании Git загружает все файлы проекта, полную историю коммитов и информацию о ветках из удалённого репозитория. Это позволяет работать с проектом локально, вносить изменения, создавать коммиты и позже синхронизировать эти изменения с удалённым репозиторием.

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ cd ..

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ mkdir Git-labs-clone

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ cd Git-labs-colone
bash: cd: Git-labs-colone: No such file or directory


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~
$ cd Git-labs-clone

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs-clone
$ git clone https://github.com/judy-tapioca/Git-labs.git
Cloning into 'Git-labs'...
remote: Enumerating objects: 27, done.
remote: Counting objects: 100% (27/27), done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 27 (delta 7), reused 27 (delta 7), pack-reused 0 (from 0)
Receiving objects: 100% (27/27), 7.73 KiB | 719.00 KiB/s, done.
Resolving deltas: 100% (7/7), done.

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs-clone
$ ls
Git-labs/

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs-clone
$ cd Git-labs

```
mkdir Git-labs-clone — создала новую папку вне репозитория
- cd Git-labs-clone — вошла в новую папку
- git clone — клонировала репозиторий с GitHub
- Все файлы совпадают с оригинальным репозиторием.


