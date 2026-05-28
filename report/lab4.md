

# Лабораторная работа №4. Знакомство с Linux

## 1. Вариант
Для определения варианта был вычислен MD5-хеш ФИО.
**Имя:** Банда Джуди
**Команда (Linux terminal):**
```bash 
echo "Банда Джуди" | md5sum
```
**Результат хеша:** `419f6583e6b4bf493568faa5d4a97ea2`
**Первый символ:** `4`
**Вариант:** Простой — Ubuntu + KDE (Kubuntu)

## 2. Изучение особенностей дистрибутива
Kubuntu — это официально признанный производный дистрибутив **Ubuntu** с рабочим окружением **KDE Plasma**.
 **Официальный сайт Kubuntu:** [https://kubuntu.org](https://kubuntu.org)  
 **Официальный сайт Ubuntu:** [https://ubuntu.com](https://ubuntu.com)

### Организация-разработчик
Kubuntu разрабатывается командой Kubuntu Council при поддержке 
Canonical Ltd. Это community-driven проект.

### Базовый дистрибутив
Kubuntu основан на **Ubuntu**, который в свою очередь основан 
на **Debian**.

### Релизы
- Новые версии выходят каждые **6 месяцев**
- LTS версии выходят каждые **2 года**
- Последний релиз: **Kubuntu 24.04 LTS (Noble Numbat)**
- Поддержка до **April 2027**

[Информация о релизах Ubuntu](https://ubuntu.com/about/release-cycle)

### Пакетный менеджер
Kubuntu использует **APT** и графический менеджер **Discover**.

| Действие | Команда |
|----------|---------|
| Поиск | `sudo apt search <имя_пакета>` |
| Установка | `sudo apt install <имя_пакета>` |
| Обновление | `sudo apt update && sudo apt upgrade` |
| Удаление | `sudo apt remove <имя_пакета>` |

![Package Manager Tools](../../images/lab4_tools.jpeg)

## 3. Минимальные системные требования

| Компонент | Минимум |
|-----------|---------|
| RAM | 2 GB |
| Disk | 25 GB |
| CPU | 2 GHz dual core |
| Display | 1024x768 |

![System Resources (htop)](../../images/lab4_htop.jpeg)

## 4. Установка ОС

### Создание виртуальной машины
- Программа виртуализации: **VirtualBox**
- Base Memory: **4096 MB**
- Processors: **2**
- Disk Size: **25 GB**
- OS: **Ubuntu 64-bit**

![VM Settings](../../images/lab4_vm_settings.png)

![Kubuntu Running](../../images/lab4_running.jpeg)

### Загрузка образа
Был загружен образ **Kubuntu 24.04.4 LTS** с официального сайта [kubuntu.org](https://kubuntu.org)