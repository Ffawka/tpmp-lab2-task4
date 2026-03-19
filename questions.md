
# КОНТРОЛЬНЫЕ ВОПРОСЫ ПО ТЕМЕ (Makefile Style)


# Вопрос 1: Примеры облачных IDE.
cloud_ides:
	<br>"Примеры облачных IDE:"
	<br>"  - Repl.it"
	<br>"  - Gitpod"
	<br>"  - GitHub Codespaces"
	<br>"  - AWS Cloud9"

# Вопрос 2: Подключение репозитория в repl.it.
repl_import:
	<br>"Процесс подключения репозитория в repl.it:"
	<br>"  1. Нажать кнопку '+' (Create new Repl)."
	<br>"  2. Выбрать вкладку 'Import from GitHub'."
	<br>"  3. Вставить URL репозитория."
	<br>"  4. Нажать 'Import from GitHub'."

# Вопрос 3: Что такое «сборка»?
build_definition:
	<br>"Сборка — это процесс преобразования исходного кода"
	<br>"в готовый программный продукт (объектные файлы, исполняемые файлы, библиотеки)."

# Вопрос 4: Утилиты для сборки.
build_utils:
	<br>"Утилиты для сборки:"
	<br>"  - Make (GNU Make)"
	<br>"  - CMake"
	<br>"  - Ninja"
	<br>"  - Apache Ant (Java)"
	<br>"  - Maven (Java)"
	<br>"  - Gradle"
	<br>"  - MSBuild (C#)"

# Вопрос 5: Для чего служит Makefile?
makefile_purpose:
	<br>"Makefile служит для автоматизации сборки проекта,"
	<br>"описания зависимостей между файлами и командами компиляции,"
	<br>"а также для обеспечения минимальной пересборки (только измененных файлов)."

# Вопрос 6: Что такое цель в Makefile? Пример.
target_example:
	<br>"Цель (target) — это конечный результат или действие, которое нужно выполнить."
	<br>"Пример:"
	<br>"\033[0;32mall: main.o utils.o\033[0m\n"
	<br>"\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	<br>"Здесь 'all' — это цель."

# Вопрос 7: Что такое связка в Makefile? Пример.
recipe_example:
	<br>"Связка (recipe) — это набор команд (shell), которые выполняются для достижения цели."
	<br>"Пример:"
	<br>"\033[0;32mclean:\033[0m\n"
	<br>"\t\033[0;33mrm -f *.o program\033[0m\n"
	<br>"\t\033[0;33m@echo 'Очистка завершена'\033[0m\n"
	<br>"Строки с 'rm' и 'echo' — это связка."

# Вопрос 8: Что такое зависимость в Makefile? Пример.
dependency_example:
	<br>"Зависимость (prerequisite) — это файлы или другие цели, которые должны быть"
	<br>"созданы/обновлены до выполнения текущей цели."
	<br>"Пример:"
	<br>"\033[0;32mprogram: main.o utils.o\033[0m\n"
	<br>"\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	<br>"Здесь 'main.o' и 'utils.o' — это зависимости цели 'program'."

# Вопрос 9: Что такое правило в Makefile? Пример.
rule_example:
	<br>"Правило (rule) — это полная конструкция, состоящая из цели,"
	<br>"зависимостей и связки."
	<br>"Пример:"
	<br>"\033[0;32m%.o: %.c\033[0m\n"
	<br>"\t\033[0;33mgcc -c $< -o $@\033[0m\n"
	<br>"Это правило говорит, как собрать любой .o файл из .c файла."

# Вопрос 10: Что такое макроопределение в Makefile? Пример.
macro_definition:
	<br>"Макроопределение (переменная) — это имя, которое хранит строку (путь, флаги, список файлов)."
	<br>"Пример:"
	<br>"\033[0;32mCC = gcc\033[0m\n"
	<br>"\033[0;32mCFLAGS = -Wall -O2\033[0m\n"
	<br>"\033[0;32mTARGET = my_program\033[0m\n"
	<br>"\033[0;32mSRCS = main.c utils.c\033[0m\n"
	<br>"Использование: \$$(CC) \$$(CFLAGS) -o \$$(TARGET) \$$(SRCS)"

# Вопрос 11: Какая связка используется для очистки проекта?
clean_recipe:
	<br>"Традиционная связка для очистки проекта — это цель 'clean'."
	<br>"Пример связки:"
	<br>"\033[0;32mclean:\033[0m\n"
	<br>"\t\033[0;33mrm -rf build/ *.o *.exe program\033[0m\n"
	<br>"\t\033[0;33m@echo 'Проект очищен.'\033[0m\n"

# Вопрос 12: Модель КИС для проектов на языке C?
kis_model:
	<br>"Модель КИС (Компиляция, Исполнение, Сборка) подразумевает разделение этапов:"
	<br>"  - Препроцессинг (обработка #define, #include)"
	<br>"  - Компиляция (получение объектных файлов .o из .c)"
	<br>"  - Линковка (связывание объектных файлов в исполняемый файл)"

# Вопрос 13: Стандарты кодирования?
coding_standards:
	<br>"Стандарты кодирования (например, GNU Style, Google Style) — это свод правил"
	<br>"по оформлению кода (отступы, имена переменных, комментарии)."
	<br>"Рекомендация следовать им обусловлена:"
	<br>"  - Улучшением читаемости кода."
	<br>"  - Облегчением поддержки и ревью."
	<br>"  - Снижением количества ошибок."

# Вопрос 14: Структура проекта согласно модели КИС и правилам сборки?
project_structure:
	<br>"Структура проекта:"
	<br>"  project-root/"
	<br>"  ├── src/         # Исходные файлы (.c)"
	<br>"  ├── include/     # Заголовочные файлы (.h)"
	<br>"  ├── obj/         # Объектные файлы (.o) (создается при сборке)"
	<br>"  ├── bin/         # Исполняемые файлы (создается при сборке)"
	<br>"  ├── Makefile     # Файл сборки"
	<br>"  └── README.md    # Документация"

# Вопрос 15: Что такое Github Actions?
github_actions:
	<br>"GitHub Actions — это платформа CI/CD (Continuous Integration/Continuous Deployment),"
	<br>"встроенная в GitHub. Позволяет автоматизировать задачи: тестирование, сборка,"
	<br>"деплой при пушах, создании Pull Request'ов и т.д."

# Вопрос 16: Что такое workflow в GitHub Actions? Пример.
workflow_example:
	<br>"Workflow — это автоматизированный процесс (один или несколько jobs),"
	<br>"описанный в YAML-файле в папке .github/workflows/."
	<br>"Пример имени файла: \033[0;32mci.yml\033[0m"
	<br>"Пример содержимого (начало):"
	<br>"\033[0;32mname: CI Pipeline\033[0m\n"
	<br>"on: [push]\n"

# Вопрос 17: Что такое event в GitHub Actions? Пример.
event_example:
	<br>"Event — это событие в репозитории, которое запускает workflow."
	<br>"Примеры:"
	<br>"  - push (отправка коммитов)"
	<br>"  - pull_request (создание/обновление PR)"
	<br>"  - schedule (запуск по расписанию)"
	<br>"\033[0mon:\033[0m\n"
	<br>"  \033[0;32mpull_request:\033[0m\n"
	<br>"    branches: [ main ]\n"

# Вопрос 18: Что такое job в GitHub Actions? Пример.
job_example:
	<br>"Job (задача) — это набор шагов (steps), выполняющихся на одном раннере."
	<br>"Пример:"
	<br>"jobs:\n"
	<br>"  \033[0;32mtest:\033[0m\n"
	<br>"    runs-on: ubuntu-latest\n"
	<br>"    steps:\n"
	<br>"      - run: echo 'Тестируем...'\n"

# Вопрос 19: Что такое step в GitHub Actions? Пример.
step_example:
	<br>"Step (шаг) — это отдельная задача внутри job (либо команда shell, либо готовый action)."
	<br>"Пример:"
	<br>"steps:\n"
	<br>"  - \033[0;32mname: Checkout code\033[0m\n"
	<br>"    uses: actions/checkout@v4\n"
	<br>"  - \033[0;32mname: Run tests\033[0m\n"
	<br>"    run: make test\n"

# Вопрос 20: Что такое action в GitHub Actions? Пример.
action_example:
	<br>"Action — это готовый переиспользуемый блок кода (как функция) для выполнения"
	<br>"часто повторяющихся задач (чек-аут, установка ЯП, деплой в облако)."
	<br>"Пример использования (actions/checkout):"
	<br>"steps:\n"
	<br>"  - \033[0;32muses: actions/checkout@v4\033[0m\n"
	<br>"    with:\n"
	<br>"      fetch-depth: 0\n"

.PHONY: all cloud_ides repl_import build_definition build_utils makefile_purpose \
        target_example recipe_example dependency_example rule_example \
        macro_definition clean_recipe kis_model coding_standards project_structure \
        github_actions workflow_example event_example job_example step_example \
        action_example
