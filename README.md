# Example Mod для Geometry Dash

Пример мода для Geometry Dash, созданного с использованием фреймворка Geode.

## Возможности

- Добавляет кастомную кнопку в главное меню
- Изменяет скорость игры через настройки
- Показывает уведомления в игре

## Установка

1. Убедитесь, что у вас установлен [Geode](https://geode-sdk.org/)
2. Скачайте `.geode` файл из релизов
3. Поместите файл в папку `geode/mods` в директории Geometry Dash
4. Запустите игру

## Разработка

### Установка Geode CLI

```bash
# Установка через Scoop (рекомендуется для Windows)
scoop bucket add extras
scoop install geode-sdk-cli

# Или скачай с https://github.com/geode-sdk/cli/releases
```

### Сборка мода

```bash
# Простой способ (рекомендуется):
geode build

# Мод будет создан в папке build/
# Файл с расширением .geode готов к использованию
```

### Ручная сборка через CMake (опционально)

```bash
# Создайте папку для сборки
mkdir build
cd build

# Сгенерируйте проект
cmake ..

# Соберите мод
cmake --build . --config Release
```

### Структура проекта

```
.
├── src/
│   └── main.cpp          # Основной код мода
├── resources/            # Ресурсы (спрайты, звуки)
├── mod.json             # Метаданные мода
├── CMakeLists.txt       # Конфигурация сборки
└── README.md
```

## Настройки

Мод добавляет следующие настройки:

- **Включить функцию**: Включает/выключает основную функцию мода
- **Скорость игры**: Изменяет скорость игры (0.5x - 3.0x)

## Полезные ссылки

- [Документация Geode](https://docs.geode-sdk.org/)
- [Geode Discord](https://discord.gg/geode)
- [Примеры модов](https://github.com/geode-sdk/examples)

## Лицензия

MIT License
