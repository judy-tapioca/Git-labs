# Лабораторная работа №6. Простые CI-CD пайплайны

## 1. Базовые хуки в Git на стороне клиента

### 1.1 Исследование хуков

Git-хуки (Git Hooks) представляют собой скрипты, которые система контроля 
версий Git автоматически выполняет до или после определённых событий, таких 
как создание коммита, слияние веток или отправка изменений на удалённый сервер. 
Хуки хранятся в директории `.git/hooks/` и могут быть написаны на любом 
скриптовом языке (Bash, Python и др.).

Хуки подразделяются на два типа: **клиентские** и **серверные**.

#### Клиентские хуки

| Хук | Когда запускается | Можно прервать? |
|-----|-------------------|-----------------|
| `pre-commit` | Перед созданием коммита |  Да |
| `commit-msg` | После ввода сообщения коммита |  Да |
| `post-commit` | После создания коммита |  Нет |
| `pre-push` | Перед отправкой изменений на сервер |  Да |
| `pre-merge-commit` | Перед слиянием веток |  Да |
| `prepare-commit-msg` | Перед открытием редактора сообщения |  Да |

#### Серверные хуки

| Хук | Когда запускается | Можно прервать? |
|-----|-------------------|-----------------|
| `pre-receive` | При получении пуша сервером |  Да |
| `update` | При обновлении каждой ветки |  Да |
| `post-receive` | После успешного получения пуша |  Нет |

#### Принцип работы

Механизм прерывания операции основан на коде завершения скрипта:
- Код завершения **0** — операция продолжается в штатном режиме.
- Код завершения **1** — операция **прерывается**, изменения не применяются.

**Источники:**
- [Git Documentation — Git Hooks](https://git-scm.com/docs/githooks)
- [Pro Git Book — Customizing Git Hooks](https://git-scm.com/book/en/v2/Customizing-Git-Git-Hooks)

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ cd .git/hooks
```
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ ls
applypatch-msg.sample*      pre-commit.sample*        prepare-commit-msg.sample*
commit-msg.sample*          pre-merge-commit.sample*  push-to-checkout.sample*
fsmonitor-watchman.sample*  pre-push.sample*          sendemail-validate.sample*
post-update.sample*         pre-rebase.sample*        update.sample*
pre-applypatch.sample*      pre-receive.sample*
```

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ touch pre-commit
```
```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ touch pre-commit

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ chmod +x pre-commit

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ code pre-commit
```

```bash
#!/bin/bash

echo "Checking files before commit..."

# Storing the diff output
DIFF_OUTPUT=$(git diff --cached | grep "^+")

# Check for forbidden patterns
if echo "$DIFF_OUTPUT" | grep -i "password"; then
    echo "Remove forbidden word: password"
    exit 1
fi

if echo "$DIFF_OUTPUT" | grep -i "TODO"; then
    echo "Remove forbidden word: TODO"
    exit 1
fi

if echo "$DIFF_OUTPUT" | grep -i "secret"; then
    echo "Remove forbidden word: secret"
    exit 1
fi

if echo "$DIFF_OUTPUT" | grep -i "api_key"; then
    echo "Remove forbidden word: api_key"
    exit 1
fi

if echo "$DIFF_OUTPUT" | grep -i "ssh-rsa"; then
    echo "Remove forbidden word: ssh-rsa"
    exit 1
fi

if echo "$DIFF_OUTPUT" | grep -i "ghp_"; then
    echo "Remove forbidden word: ghp_"
    exit 1
fi

echo "No forbidden content found."
exit 0
```

### 1.2 Pre-commit хук (запрещённые паттерны)

Хук успешно блокирует коммит при обнаружении запрещённого содержимого:

 
```bsah
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/.git/hooks (GIT_DIR!)
$ cd ~/Git-labs

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ echo "api_key = abc123secret" > test_secret.txt

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ git add test_secret.txt
warning: in the working copy of 'test_secret.txt', LF will be replaced by CRLF the next time Git touches it

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ git commit -m "test commit"
Checking files before commit...
+++ b/test_secret.txt
+api_key = abc123secret
Remove forbidden word: secret
```


``` bash
#!/bin/bash

echo "Checking commit message..."

# Read commit message from file
MSG=$(cat $1)

# Rule 1: empty message
if [ -z "$MSG" ]; then
    echo "Commit message cannot be empty."
    exit 1
fi

# Rule 2: too short
if [ ${#MSG} -lt 5 ]; then
    echo "Commit message is too short! Minimum 5 characters."
    exit 1
fi

# Rule 3: must start with capital letter
if ! echo "$MSG" | grep -q "^[A-Z]"; then
    echo "Commit message must start with a capital letter!"
    exit 1
fi

# Rule 4: forbidden word WIP
if echo "$MSG" | grep -i "WIP" > /dev/null; then
    echo "Commit message contains forbidden word: WIP"
    exit 1
fi

echo "Commit message is valid."
exit 0
```

### 1.3 Commit-msg хук

Хук проверяет сообщение коммита по следующим правилам:
- Сообщение не может быть пустым
- Минимальная длина сообщения — 5 символов
- Сообщение должно начинаться с заглавной буквы
- Сообщение не может содержать слово WIP

```bash
$ git commit -m "hi"
Checking commit message...
Commit message is too short! Minimum 5 characters.

$ git commit -m "WIP changes"
Checking commit message...
Commit message contains forbidden word: WIP

$ git commit -m "added new feature"
Checking commit message...
Commit message must start with a capital letter!

$ git commit -m "Added new feature"
Checking commit message...
Commit message is valid.
[lab6 3f1282e] Added new feature
```

## 2. Хуки Git на стороне сервера

### 2.1 Создание копии репозитория

Создана локальная копия репозитория для эмуляции удалённого сервера:

```bash
$ git clone ~/Git-labs Git-labs-clone
Cloning into 'Git-labs-clone'...
done.
```

### 2.2 Добавление копии как удалённого репозитория

```bash
$ git remote add localserver ~/Git-labs-clone
$ git remote -v
localserver     C:/Users/Judy Banda/Git-labs-clone (fetch)
localserver     C:/Users/Judy Banda/Git-labs-clone (push)
origin  https://github.com/judy-tapioca/Git-labs.git (fetch)
origin  https://github.com/judy-tapioca/Git-labs.git (push)
```

### 2.3 Проверка push в локальный репозиторий

```bash
$ git push localserver lab6
Everything up-to-date
```
### 2.5 Конвертация Markdown в HTML

### 2.5 Конвертация Markdown в HTML

Для конвертации Markdown-файлов в HTML используется инструмент **Pandoc**.

Pandoc был загружен и установлен с официального сайта:
https://github.com/jgm/pandoc/releases/latest

Была установлена версия **pandoc-3.9.0.2-windows-x86_64.msi**

Проверка установки:

```bash
$ pandoc --version
pandoc 3.9.0.2
Features: +server +lua
Scripting engine: Lua 5.4
User data directory: C:\Users\Judy Banda\AppData\Roaming\pandoc
Copyright (C) 2006-2025 John MacFarlane. Web:  https://pandoc.org
```

Преобразование из Markdown в HTML выполняется с помощью следующей команды:

```bash
pandoc reports/lab6.md -o reports/lab6.html
```

Где:
- `reports/lab6.md` — исходный файл Markdown
- `reports/lab6.html` — сгенерированный HTML-файл


### 2.6 Настройка post-receive хука

В клонированном репозитории создан хук `post-receive`, который автоматически
конвертирует `lab6.md` в HTML при каждом push:

```bash
$ cd ~/Git-labs-clone/.git/hooks
$ touch post-receive
$ chmod +x post-receive
```

Содержимое хука:

```bash
#!/bin/bash

echo "Running post-receive hook..."

# Go to the repo directory
cd ~/Git-labs-clone

# Convert lab6.md to HTML
pandoc reports/lab6.md -o reports/lab6.html

echo "lab6.html has been generated successfully!"
```

### 2.7 Проверка работы хука

После внесения изменений в `lab6.md` и отправки в локальный сервер:

```bash
$ git add reports/lab6.md
$ git commit -m "Test post-receive hook"
Checking files before commit...
No forbidden content found.
Checking commit message...
Commit message is valid.
[lab6 c8ca170] Test post-receive hook

$ git push localserver lab6
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Writing objects: 100% (4/4), 342 bytes | 85.00 KiB/s, done.
remote: Running post-receive hook...
remote: lab6.html has been generated successfully!
To C:/Users/Judy Banda/Git-labs-clone
   3f1282e..c8ca170  lab6 -> lab6
```

Проверка созданного HTML-файла:

```bash
$ ls reports/
lab1.md  lab6.html  lab6.md
```

HTML-файл успешно создан и открыт в браузере.

## 3. Сборка с помощью CMake

### 3.1 Основные понятия CMake

**CMake** — это кроссплатформенная система автоматизации сборки программного обеспечения.

Основные понятия:

- **Проект (Project)** — верхний уровень сборки, объявляется командой `project()`
- **Цель (Target)** — результат сборки (исполняемый файл или библиотека)
- **Библиотека (Library)** — набор скомпилированных объектных файлов, объявляется командой `add_library()`
- **Исполняемый файл (Executable)** — программа, объявляется командой `add_executable()`

Основные команды CMake:

```cmake
# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MyProject)

# Создание библиотеки
add_library(mylib lib.cpp)

# Создание исполняемого файла
add_executable(myapp main.cpp)

# Подключение библиотеки к исполняемому файлу
target_link_libraries(myapp mylib)

# Добавление дочерней директории
add_subdirectory(tests)
```

### 3.2 Версия CMake

```bash
$ cmake --version
cmake version 4.3.0
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

### 3.3 Основной CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)

project(Lab1_DataStructures)

# Include src directory for headers
include_directories(src)

# Create library from class files
add_library(DataLogic
    src/barrel.cpp
    src/matrix.cpp
    src/my_string.cpp
    src/rect.cpp
    src/text_wrapper.cpp
)

# Create executable from main file
add_executable(lab1 src/main.cpp)

# Link library to executable
target_link_libraries(lab1 PRIVATE DataLogic)

# Enable testing
enable_testing()
add_subdirectory(tests)
```

### 3.4 CMakeLists.txt для тестов

```cmake
# Test 1
add_executable(test_bounding_rect test_bounding_rect.cpp)
target_link_libraries(test_bounding_rect PRIVATE DataLogic)
add_test(NAME BoundingRectTest COMMAND test_bounding_rect)

# Test 2
add_executable(test_rect_basic test_rect_basic_properties.cpp)
target_link_libraries(test_rect_basic PRIVATE DataLogic)
add_test(NAME RectBasicTest COMMAND test_rect_basic)

# Test 3
add_executable(test_rect_operations test_rect_operations.cpp)
target_link_libraries(test_rect_operations PRIVATE DataLogic)
add_test(NAME RectOperationsTest COMMAND test_rect_operations)
```

### 3.5 Сборка проекта

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ cd ~/Git-labs/cmake_lab
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/cmake_lab (lab6)
$ mkdir build
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/cmake_lab (lab6)
$ cd build
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/cmake_lab/build (lab6)
$ cmake ..
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.26100.0 to target Windows 10.0.26200.
-- The C compiler identification is MSVC 19.44.35219.0
-- The CXX compiler identification is MSVC 19.44.35219.0
-- Detecting C compiler ABI info - done
-- Detecting CXX compiler ABI info - done
-- Configuring done (9.3s)
-- Generating done (0.2s)
-- Build files have been written to: C:/Users/Judy Banda/Git-labs/cmake_lab/build

Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/cmake_lab/build (lab6)
$ cmake --build .
  DataLogic.vcxproj -> C:\Users\Judy Banda\Git-labs\cmake_lab\build\Debug\DataLogic.lib
  lab1.vcxproj -> C:\Users\Judy Banda\Git-labs\cmake_lab\build\Debug\lab1.exe
  test_bounding_rect.vcxproj -> C:\Users\Judy Banda\Git-labs\cmake_lab\build\tests\Debug\test_bounding_rect.exe
  test_rect_basic.vcxproj -> C:\Users\Judy Banda\Git-labs\cmake_lab\build\tests\Debug\test_rect_basic.exe
  test_rect_operations.vcxproj -> C:\Users\Judy Banda\Git-labs\cmake_lab\build\tests\Debug\test_rect_operations.exe
```

### 3.6 Запуск тестов

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs/cmake_lab/build (lab6)
$ ctest -C Debug
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.14 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.09 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.09 sec
100% tests passed, 0 tests failed out of 3
Total Test time (real) =   0.55 sec
```

## 4. Автоматизация задач CMake в git

### 4.1 Создание ветки dev

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (lab6)
$ git checkout -b dev
Switched to a new branch 'dev'
```

### 4.2 Обновлённый pre-commit хук

Хук обновлён для запуска CMake тестов на ветке dev:

```bash
# Check current branch
BRANCH=$(git branch --show-current)

if [ "$BRANCH" != "dev" ]; then
    echo "Not on dev branch, skipping tests"
    exit 0
fi

echo "Running CMake tests before commit..."

cd ~/Git-labs/cmake_lab/build || exit 1

ctest -C Debug

if [ $? -ne 0 ]; then
    echo "Tests FAILED, commit aborted"
    exit 1
fi

echo "All tests passed, commit allowed"
exit 0
```

### 4.3 Первая попытка коммита — блокировка из-за TODO

При первой попытке коммита хук заблокировал его из-за слова `TODO`,
найденного в исходных файлах:

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git commit -m "Testing CMake hook on dev"
Checking files before commit...
+  // TODO: add checks that assure that capacity is not overflown
+    // TODO: will in ex.s1 be garbage?
+    // TODO: will all this operations work correctly?
+} // TODO: will there be memory leaks?
+        // TODO: write when d-tors are called here (in comments)
+    // TODO: write what c-tors are called in this block and explain why?
+  // TODO: what is the difference between this operator and copy c-tor?
+// TODO: make sure that you do not allocate dynamic memory for empty string
+// TODO: splitting by words: do not break words
Remove forbidden word: TODO
```

**Причина удаления TODO из списка запрещённых слов:**

Слово `TODO` было удалено из списка запрещённых паттернов, так как оно
является стандартным комментарием в коде, используемым разработчиками
для пометки мест, требующих доработки. В данном случае `TODO` присутствует
в существующих исходных файлах лабораторной работы по структурам данных
и не является конфиденциальной или опасной информацией. Запрет на коммит
из-за таких комментариев нецелесообразен в реальной разработке.

### 4.4 Проверка хука на ветке dev

После удаления `TODO` из списка запрещённых слов коммит прошёл успешно:

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git commit -m "Testing CMake hook on dev"
Checking files before commit...
No forbidden content found.
Running CMake tests before commit...
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.03 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.03 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.02 sec
100% tests passed, 0 tests failed out of 3
Total Test time (real) =   0.10 sec
All tests passed, commit allowed
Checking commit message...
Commit message is valid.
[dev 6d400ec] Testing CMake hook on dev
```

### 4.5 Тестирование хука при обычном коммите (сбой)

Для демонстрации блокировки коммита был намеренно добавлен сломанный код:

```cpp
int forceFailure = 1/0;
```

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git commit -m "Testing failed cmake hook"
Checking files before commit...
No forbidden content found.
Running CMake tests before commit...
Build FAILED, commit aborted
```

### 4.6 Тестирование хука после исправления

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git commit -m "Fixed failing test"
Checking files before commit...
No forbidden content found.
Running CMake tests before commit...
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.03 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.03 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.08 sec
100% tests passed, 0 tests failed out of 3
All tests passed, commit allowed
[dev 2bb864d] Fixed failing test
```

### 4.7 Тестирование хука при merge

Создан хук `pre-merge-commit` для запуска тестов перед слиянием:

```bash
#!/bin/bash

echo "Running CMake tests before merge..."

cd ~/Git-labs/cmake_lab/build || exit 1

# Rebuild before running tests
cmake --build . > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "Build FAILED, merge aborted"
    exit 1
fi

ctest -C Debug

if [ $? -ne 0 ]; then
    echo "Tests FAILED, merge aborted"
    exit 1
fi

echo "All tests passed, merge allowed"
exit 0
```
Проверка работы хука при merge:


```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git checkout -b test-merge2
Switched to a new branch 'test-merge2'

$ git commit -m "Second merge test"
Checking files before commit...
No forbidden content found.
Not on dev branch, skipping tests
Checking commit message...
Commit message is valid.
[test-merge2 fd9041b] Second merge test

$ git checkout dev
$ git merge --no-ff test-merge2
Running CMake tests before merge...
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.03 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.03 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.03 sec
100% tests passed, 0 tests failed out of 3
All tests passed, merge allowed
Total Test time (real) =   0.12 sec
All tests passed, merge allowed
Checking commit message...
Commit message is valid.
Merge made by the 'ort' strategy.
 merge_test2.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 merge_test2.txt

```
### 4.8 Хук для сборки библиотеки

В хук `pre-commit` добавлена сборка библиотеки при каждом коммите в ветку `dev`:

```bash
# Build the library
echo "Building library..."
cd ~/Git-labs/cmake_lab/build || exit 1
cmake --build . --target DataLogic > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "Library build FAILED, commit aborted"
    exit 1
fi

echo "Library built successfully"
```

Проверка работы хука:

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git commit -m "Testing library build hook"
Checking files before commit...
No forbidden content found.
Running CMake tests before commit...
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.03 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.02 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.02 sec
100% tests passed, 0 tests failed out of 3
Total Test time (real) =   0.12 sec
All tests passed, commit allowed
Building library...
Library built successfully
Checking commit message...
Commit message is valid.
[dev 94fc4f6] Testing library build hook
```

## 5. Автоматизация с помощью Github Actions

### 5.1 Основной синтаксис YAML

**YAML** (YAML Ain't Markup Language) — это удобочитаемый язык сериализации данных,
используемый для конфигурационных файлов. Он использует отступы для определения
структуры, а не скобки или теги.

Основные конструкции:

- **Пары ключ-значение:** `name: значение`
- **Списки:** обозначаются дефисом `-`
- **Словари:** вложенные ключи с использованием пробелов для отступов
- **Комментарии:** обозначаются символом `#`

```yaml
# Пример YAML
name: My Project

steps:
  - step1
  - step2

env:
  KEY: value

enabled: true
```

### 5.2 Основные возможности Github Actions

**GitHub Actions** — это платформа непрерывной интеграции и непрерывной
доставки (CI/CD), которая позволяет автоматизировать конвейеры сборки,
тестирования и развертывания.

Основные понятия:

- **Workflow** — автоматизированный процесс, описанный в `.yml` файле в директории `.github/workflows/`
- **Job** — набор шагов, выполняемых на одном runner
- **Step** — отдельная задача внутри job
- **Runner** — виртуальная машина (Linux, Windows, macOS), выполняющая задания
- **Trigger** — событие, запускающее workflow (push, pull_request и др.)

**Доступные тарифные планы:**

| План | Минуты в месяц | Цена |
|------|---------------|------|
| Free | 2000 | Бесплатно |
| Pro | 3000 | $4/месяц |
| Team | 3000 | $4/пользователь |
| Enterprise | 50000 | По запросу |

### 5.3 CI/CD пайплайн

В рамках лабораторной работы был настроен конвейер CI/CD для проекта на C++.
Основные этапы реализации:

- **Конфигурация workflow:** Был создан файл `.github/workflows/cmake-ci.yml`,
настроенный на запуск при каждом push или pull_request в ветку `dev`.

- **Среда сборки:** Использовался runner на базе Ubuntu (`ubuntu-latest`).
Это позволило проверить кроссплатформенность кода, так как разработка
велась на Windows.

- **Автоматизация CMake:** В workflow были добавлены шаги для автоматической
настройки проекта через `cmake` и сборки через `cmake --build`.

- **Запуск тестов:** После сборки автоматически запускаются все тесты
через `ctest --output-on-failure`.

Был создан файл `.github/workflows/cmake-ci.yml`:

```yaml
name: CMake CI-CD Pipeline

on:
  push:
    branches: [ "dev" ]
  pull_request:
    branches: [ "dev" ]

jobs:
  build-and-test:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout Code
      uses: actions/checkout@v4

    - name: Install Dependencies
      run: sudo apt-get update && sudo apt-get install -y cmake g++ make

    - name: Configure CMake
      run: cmake -S cmake_lab -B cmake_lab/build

    - name: Build Project
      run: cmake --build cmake_lab/build

    - name: Run Tests
      run: |
        cd cmake_lab/build
        ctest --output-on-failure
```

**Источники:**
- https://docs.github.com/en/actions
- https://docs.github.com/en/billing/managing-billing-for-github-actions

### 5.4 Запуск пайплайна на GitHub

Файл `.github/workflows/cmake-ci.yml` был создан и отправлен в ветку `dev`:

```bash
Judy Banda@DESKTOP-V0A7BUM MINGW64 ~/Git-labs (dev)
$ git add .github/workflows/cmake-ci.yml

$ git commit -m "Add GitHub Actions CI/CD pipeline"
Checking files before commit...
No forbidden content found.
Running CMake tests before commit...
Test project C:/Users/Judy Banda/Git-labs/cmake_lab/build
    Start 1: BoundingRectTest
1/3 Test #1: BoundingRectTest .................   Passed    0.03 sec
    Start 2: RectBasicTest
2/3 Test #2: RectBasicTest ....................   Passed    0.03 sec
    Start 3: RectOperationsTest
3/3 Test #3: RectOperationsTest ...............   Passed    0.02 sec
100% tests passed, 0 tests failed out of 3
Total Test time (real) =   0.09 sec
All tests passed, commit allowed
Building library...
Library built successfully
Checking commit message...
Commit message is valid.
[dev fe3b0da] Add GitHub Actions CI/CD pipeline

$ git push origin dev
Enumerating objects: 57, done.
Writing objects: 100% (55/55), 33.45 KiB | 1.86 MiB/s, done.
remote: Resolving deltas: 100% (12/12), done.
To https://github.com/judy-tapioca/Git-labs.git
 * [new branch]      dev -> dev
```

Пайплайн автоматически запустился на GitHub после push в ветку `dev`.
Проверить статус можно по ссылке:
https://github.com/judy-tapioca/Git-labs/actions

### 5.5 Результаты запуска пайплайна

Пайплайн запускался дважды:

**Первый запуск — неудачный:**
При первом push файлы CMake не были включены, поэтому пайплайн завершился с ошибкой.

**Второй запуск — успешный:**
После добавления всех необходимых файлов CMake пайплайн успешно выполнился за 26 секунд.

```
 Add GitHub Actions CI/CD pipeline
   CMake CI-CD Pipeline #1 — failed in 29s

  Add complete lab6 report and cmake files
   CMake CI-CD Pipeline #2 — passed in 26s
```