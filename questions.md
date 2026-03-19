
# КОНТРОЛЬНЫЕ ВОПРОСЫ ПО ТЕМЕ (Makefile Style)


# Вопрос 1: Примеры облачных IDE.
cloud_ides:
	<br>"Примеры облачных IDE:"
	"  - Repl.it"
	"  - Gitpod"
	"  - GitHub Codespaces"
	"  - AWS Cloud9"

# Вопрос 2: Подключение репозитория в repl.it.
repl_import:
	"Процесс подключения репозитория в repl.it:"
	"  1. Нажать кнопку '+' (Create new Repl)."
	"  2. Выбрать вкладку 'Import from GitHub'."
	"  3. Вставить URL репозитория."
	"  4. Нажать 'Import from GitHub'."

# Вопрос 3: Что такое «сборка»?
build_definition:
	"Сборка — это процесс преобразования исходного кода"
	"в готовый программный продукт (объектные файлы, исполняемые файлы, библиотеки)."

# Вопрос 4: Утилиты для сборки.
build_utils:
	"Утилиты для сборки:"
	"  - Make (GNU Make)"
	"  - CMake"
	"  - Ninja"
	"  - Apache Ant (Java)"
	"  - Maven (Java)"
	"  - Gradle"
	"  - MSBuild (C#)"

# Вопрос 5: Для чего служит Makefile?
makefile_purpose:
	"Makefile служит для автоматизации сборки проекта,"
	"описания зависимостей между файлами и командами компиляции,"
	"а также для обеспечения минимальной пересборки (только измененных файлов)."

# Вопрос 6: Что такое цель в Makefile? Пример.
target_example:
	"Цель (target) — это конечный результат или действие, которое нужно выполнить."
	"Пример:"
	"\033[0;32mall: main.o utils.o\033[0m\n"
	"\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	"Здесь 'all' — это цель."

# Вопрос 7: Что такое связка в Makefile? Пример.
recipe_example:
	"Связка (recipe) — это набор команд (shell), которые выполняются для достижения цели."
	"Пример:"
	"\033[0;32mclean:\033[0m\n"
	"\t\033[0;33mrm -f *.o program\033[0m\n"
	"\t\033[0;33m@echo 'Очистка завершена'\033[0m\n"
	"Строки с 'rm' и 'echo' — это связка."

# Вопрос 8: Что такое зависимость в Makefile? Пример.
dependency_example:
	"Зависимость (prerequisite) — это файлы или другие цели, которые должны быть"
	"созданы/обновлены до выполнения текущей цели."
	"Пример:"
	"\033[0;32mprogram: main.o utils.o\033[0m\n"
	"\t\033[0;33mgcc -o program main.o utils.o\033[0m\n"
	"Здесь 'main.o' и 'utils.o' — это зависимости цели 'program'."

# Вопрос 9: Что такое правило в Makefile? Пример.
rule_example:
	"Правило (rule) — это полная конструкция, состоящая из цели,"
	"зависимостей и связки."
	"Пример:"
	"\033[0;32m%.o: %.c\033[0m\n"
	"\t\033[0;33mgcc -c $< -o $@\033[0m\n"
	"Это правило говорит, как собрать любой .o файл из .c файла."

# Вопрос 10: Что такое макроопределение в Makefile? Пример.
macro_definition:
	"Макроопределение (переменная) — это имя, которое хранит строку (путь, флаги, список файлов)."
	"Пример:"
	"\033[0;32mCC = gcc\033[0m\n"
	"\033[0;32mCFLAGS = -Wall -O2\033[0m\n"
	"\033[0;32mTARGET = my_program\033[0m\n"
	"\033[0;32mSRCS = main.c utils.c\033[0m\n"
	"Использование: \$$(CC) \$$(CFLAGS) -o \$$(TARGET) \$$(SRCS)"

# Вопрос 11: Какая связка используется для очистки проекта?
clean_recipe:
	"Традиционная связка для очистки проекта — это цель 'clean'."
	"Пример связки:"
	"\033[0;32mclean:\033[0m\n"
	"\t\033[0;33mrm -rf build/ *.o *.exe program\033[0m\n"
	"\t\033[0;33m@echo 'Проект очищен.'\033[0m\n"

# Вопрос 12: Модель КИС для проектов на языке C?
kis_model:
	"Модель КИС (Компиляция, Исполнение, Сборка) подразумевает разделение этапов:"
	"  - Препроцессинг (обработка #define, #include)"
	"  - Компиляция (получение объектных файлов .o из .c)"
	"  - Линковка (связывание объектных файлов в исполняемый файл)"

# Вопрос 13: Стандарты кодирования?
coding_standards:
	"Стандарты кодирования (например, GNU Style, Google Style) — это свод правил"
	"по оформлению кода (отступы, имена переменных, комментарии)."
	"Рекомендация следовать им обусловлена:"
	"  - Улучшением читаемости кода."
	"  - Облегчением поддержки и ревью."
	"  - Снижением количества ошибок."

# Вопрос 14: Структура проекта согласно модели КИС и правилам сборки?
project_structure:
	"Структура проекта:"
	"  project-root/"
	"  ├── src/         # Исходные файлы (.c)"
	"  ├── include/     # Заголовочные файлы (.h)"
	"  ├── obj/         # Объектные файлы (.o) (создается при сборке)"
	"  ├── bin/         # Исполняемые файлы (создается при сборке)"
	"  ├── Makefile     # Файл сборки"
	"  └── README.md    # Документация"

# Вопрос 15: Что такое Github Actions?
github_actions:
	"GitHub Actions — это платформа CI/CD (Continuous Integration/Continuous Deployment),"
	"встроенная в GitHub. Позволяет автоматизировать задачи: тестирование, сборка,"
	"деплой при пушах, создании Pull Request'ов и т.д."

# Вопрос 16: Что такое workflow в GitHub Actions? Пример.
workflow_example:
	"Workflow — это автоматизированный процесс (один или несколько jobs),"
	"описанный в YAML-файле в папке .github/workflows/."
	"Пример имени файла: \033[0;32mci.yml\033[0m"
	"Пример содержимого (начало):"
	"\033[0;32mname: CI Pipeline\033[0m\n"
	"on: [push]\n"

# Вопрос 17: Что такое event в GitHub Actions? Пример.
event_example:
	"Event — это событие в репозитории, которое запускает workflow."
	"Примеры:"
	"  - push (отправка коммитов)"
	"  - pull_request (создание/обновление PR)"
	"  - schedule (запуск по расписанию)"
	"\033[0mon:\033[0m\n"
	"  \033[0;32mpull_request:\033[0m\n"
	"    branches: [ main ]\n"

# Вопрос 18: Что такое job в GitHub Actions? Пример.
job_example:
	"Job (задача) — это набор шагов (steps), выполняющихся на одном раннере."
	"Пример:"
	"jobs:\n"
	"  \033[0;32mtest:\033[0m\n"
	"    runs-on: ubuntu-latest\n"
	"    steps:\n"
	"      - run: echo 'Тестируем...'\n"

# Вопрос 19: Что такое step в GitHub Actions? Пример.
step_example:
	"Step (шаг) — это отдельная задача внутри job (либо команда shell, либо готовый action)."
	"Пример:"
	"steps:\n"
	"  - \033[0;32mname: Checkout code\033[0m\n"
	"    uses: actions/checkout@v4\n"
	"  - \033[0;32mname: Run tests\033[0m\n"
	"    run: make test\n"

# Вопрос 20: Что такое action в GitHub Actions? Пример.
action_example:
	"Action — это готовый переиспользуемый блок кода (как функция) для выполнения"
	"часто повторяющихся задач (чек-аут, установка ЯП, деплой в облако)."
	"Пример использования (actions/checkout):"
	"steps:\n"
	"  - \033[0;32muses: actions/checkout@v4\033[0m\n"
	"    with:\n"
	"      fetch-depth: 0\n"

.PHONY: all cloud_ides repl_import build_definition build_utils makefile_purpose \
        target_example recipe_example dependency_example rule_example \
        macro_definition clean_recipe kis_model coding_standards project_structure \
        github_actions workflow_example event_example job_example step_example \
        action_example
