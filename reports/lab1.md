# Отчет по лабораторной работе №1

ЭТАП 1
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


ЭТАП 2

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

**Описание:**


ЭТАП 3
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

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git add .

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git status
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
        new file:   reports/lab1.md


Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (main)
$ git diff --cached reports/lab1.md
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
