import calendar
import re
from datetime import datetime
from pathlib import Path

root = Path(".")

SUPPORTED_EXTENSIONS = {
    ".cpp",
    ".java",
    ".py",
    ".c",
    ".js",
    ".ts",
}


def format_problem_name(filename):
    """
    001-two-sum -> #1 Two Sum
    128-longest-consecutive-sequence -> #128 Longest Consecutive Sequence
    """

    parts = filename.split("-")

    if not parts:
        return filename

    try:
        number = int(parts[0])
        title = " ".join(word.capitalize() for word in parts[1:])
        return f"#{number} {title}"
    except ValueError:
        return filename.replace("-", " ").title()


def get_question_key(filename):
    """
    Returns a unique key used to identify a question.

    Examples:

    001-two-sum.cpp
    001-two-sum.py
        -> same question

    1861-rotating-box.cpp
    1861-rotating-box.py
        -> same question

    gfg-next-greater-element.cpp
        -> based on filename
    """

    stem = Path(filename).stem

    # LeetCode-style filenames:
    # 001-two-sum
    # 1861-rotating-box
    match = re.match(r"^(\d+)(?:-|$)", stem)

    if match:
        # Question number is the unique identifier
        return f"leetcode:{int(match.group(1))}"

    # Non-numbered problems:
    # normalize the filename
    return f"other:{stem.lower()}"


# ---------------------------------------------------------
# Find date folders inside Month Year folders
# ---------------------------------------------------------

folders = []

for month_folder in root.iterdir():

    if not month_folder.is_dir():
        continue

    for date_folder in month_folder.iterdir():

        if not date_folder.is_dir():
            continue

        try:
            date = datetime.strptime(
                date_folder.name,
                "%Y-%m-%d"
            ).date()
        except ValueError:
            continue

        files = sorted(
            [
                format_problem_name(file.stem)
                for file in date_folder.iterdir()
                if file.is_file()
                and file.suffix.lower() in SUPPORTED_EXTENSIONS
            ]
        )

        # -------------------------------------------------
        # Count UNIQUE questions
        # -------------------------------------------------

        question_keys = set()

        for file in date_folder.iterdir():

            if not file.is_file():
                continue

            if file.suffix.lower() not in SUPPORTED_EXTENSIONS:
                continue

            question_keys.add(
                get_question_key(file.name)
            )

        folders.append(
            {
                "date": date,
                "date_string": date_folder.name,

                # IMPORTANT:
                # Count unique questions, not files
                "count": len(question_keys),

                # Keep all files for reference
                "files": files,

                "month_folder": month_folder.name,
            }
        )


# ---------------------------------------------------------
# Sort dates - newest first
# ---------------------------------------------------------

folders.sort(
    key=lambda x: x["date"],
    reverse=True
)


# ---------------------------------------------------------
# Create lookup for calendar
# ---------------------------------------------------------

practice_days = {
    folder["date"]: folder
    for folder in folders
}


# ---------------------------------------------------------
# Calculate streaks
# ---------------------------------------------------------

dates = sorted(practice_days.keys())

current_streak = 0
longest_streak = 0

if dates:

    # Longest streak
    streak = 1
    longest_streak = 1

    for i in range(1, len(dates)):

        if (dates[i] - dates[i - 1]).days == 1:
            streak += 1
        else:
            streak = 1

        longest_streak = max(
            longest_streak,
            streak
        )

    # Current streak
    current_streak = 1

    for i in range(len(dates) - 1, 0, -1):

        if (dates[i] - dates[i - 1]).days == 1:
            current_streak += 1
        else:
            break


# ---------------------------------------------------------
# Stats
# ---------------------------------------------------------

# IMPORTANT:
# These now use UNIQUE QUESTION counts.
total_questions = sum(
    folder["count"]
    for folder in folders
)

total_days = len(folders)


# ---------------------------------------------------------
# Generate README
# ---------------------------------------------------------

lines = []

lines.append("# 🚀 DSA Practice\n")


# ---------------------------------------------------------
# Stats
# ---------------------------------------------------------

lines.append("## 📊 Stats\n")

lines.append(
    f"- 📅 Total Days Practiced: **{total_days}**"
)

lines.append(
    f"- 📝 Total Questions Solved: **{total_questions}**"
)

lines.append(
    f"- 🔥 Current Streak: **{current_streak} Days**"
)

lines.append(
    f"- 🏆 Longest Streak: **{longest_streak} Days**"
)

lines.append(
    f"- 🕒 Last Updated: **{datetime.now().strftime('%Y-%m-%d %H:%M')}**\n"
)

lines.append("---\n")


# ---------------------------------------------------------
# Monthly Calendars
# ---------------------------------------------------------

months = sorted(
    {
        (date.year, date.month)
        for date in dates
    },
    reverse=True
)

calendar.setfirstweekday(calendar.MONDAY)


for year, month in months:

    month_name = datetime(
        year,
        month,
        1
    ).strftime("%B %Y")

    # -----------------------------------------------------
    # Collapsible Month
    # -----------------------------------------------------

    lines.append("<details>")

    lines.append(
        f"<summary><strong>📅 {month_name}</strong></summary>"
    )

    lines.append("")

    # -----------------------------------------------------
    # Calendar
    # -----------------------------------------------------

    lines.append(
        "| Mon | Tue | Wed | Thu | Fri | Sat | Sun |"
    )

    lines.append(
        "|:---:|:---:|:---:|:---:|:---:|:---:|:---:|"
    )

    month_calendar = calendar.monthcalendar(
        year,
        month
    )

    for week in month_calendar:

        cells = []

        for day in week:

            # Empty cell before/after month
            if day == 0:
                cells.append(" ")
                continue

            current_date = datetime(
                year,
                month,
                day
            ).date()

            folder = practice_days.get(
                current_date
            )

            if folder:

                count = folder["count"]

                problem_word = (
                    "Q"
                    if count == 1
                    else "Qs"
                )

                # Encode spaces in "Month Year"
                month_folder = folder[
                    "month_folder"
                ].replace(
                    " ",
                    "%20"
                )

                folder_url = (
                    f"./{month_folder}/"
                    f"{folder['date_string']}/"
                )

                # No green box.
                # Date itself is clickable.
                cell = (
                    f"[**{day}**]({folder_url})"
                    f"<br>"
                    f"`{count} {problem_word}`"
                )

                cells.append(cell)

            else:

                cells.append(str(day))

        lines.append(
            "| " + " | ".join(cells) + " |"
        )

    lines.append("")

    lines.append(
        "<sub>"
        "Click a practice date to open that day's folder."
        "</sub>"
    )

    lines.append("")

    # Close month
    lines.append("</details>")
    lines.append("")


# ---------------------------------------------------------
# Footer
# ---------------------------------------------------------

lines.append("---\n")

lines.append(
    "Built automatically from the repository's daily practice folders."
)


# ---------------------------------------------------------
# Write README
# ---------------------------------------------------------

Path("README.md").write_text(
    "\n".join(lines),
    encoding="utf-8"
)
