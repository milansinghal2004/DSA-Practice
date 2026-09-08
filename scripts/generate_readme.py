from datetime import datetime
from pathlib import Path

root = Path(".")


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
        # Non-LeetCode filenames
        return filename.replace("-", " ").title()


folders = []

# ---------------------------------------------------------
# Find date folders inside Month Year folders
# ---------------------------------------------------------

for month_folder in root.iterdir():

    if not month_folder.is_dir():
        continue

    for item in month_folder.iterdir():

        if not item.is_dir():
            continue

        try:
            date = datetime.strptime(item.name, "%Y-%m-%d").date()
        except ValueError:
            continue

        files = sorted(
            [
                format_problem_name(f.stem)
                for f in item.iterdir()
                if f.is_file()
                and f.suffix in [".cpp", ".java", ".py", ".c", ".js", ".ts"]
            ]
        )

        folders.append(
            {
                "date": date,
                "date_string": item.name,
                "count": len(files),
                "files": files,
            }
        )


# Latest dates first
folders.sort(key=lambda x: x["date"], reverse=True)


# ---------------------------------------------------------
# Calculate streaks
# ---------------------------------------------------------

dates = sorted(folder["date"] for folder in folders)

current_streak = 0
longest_streak = 0

if dates:
    current_streak = 1
    longest_streak = 1

    streak = 1

    # Longest streak
    for i in range(1, len(dates)):
        if (dates[i] - dates[i - 1]).days == 1:
            streak += 1
        else:
            streak = 1

        longest_streak = max(longest_streak, streak)

    # Current streak
    for i in range(len(dates) - 1, 0, -1):
        if (dates[i] - dates[i - 1]).days == 1:
            current_streak += 1
        else:
            break


# ---------------------------------------------------------
# Stats
# ---------------------------------------------------------

total_questions = sum(x["count"] for x in folders)
total_days = len(folders)


# ---------------------------------------------------------
# Generate README
# ---------------------------------------------------------

lines = []

lines.append("# 🚀 DSA Practice\n")

lines.append("## 📊 Stats\n")
lines.append(f"- 📅 Total Days Practiced: **{total_days}**")
lines.append(f"- 📝 Total Questions Solved: **{total_questions}**")
lines.append(f"- 🔥 Current Streak: **{current_streak} Days**")
lines.append(f"- 🏆 Longest Streak: **{longest_streak} Days**")
lines.append(
    f"- 🕒 Last Updated: **{datetime.now().strftime('%Y-%m-%d %H:%M')}**\n"
)

lines.append("---\n")


# ---------------------------------------------------------
# Group by Month / Year
# ---------------------------------------------------------

current_month = None

for folder in folders:

    date = folder["date"]
    month_key = (date.year, date.month)

    if month_key != current_month:
        current_month = month_key

        lines.append(
            f"## 📆 {date.strftime('%B %Y')}\n"
        )

    count = folder["count"]
    problem_word = "Problem" if count == 1 else "Problems"

    lines.append("<details>")

    lines.append(
        f"<summary><strong>"
        f"{folder['date_string']} "
        f"({count} {problem_word})"
        f"</strong></summary>"
    )

    lines.append("")

    for problem in folder["files"]:
        lines.append(f"- ✅ {problem}")

    lines.append("")
    lines.append("</details>")
    lines.append("")


lines.append("---")

Path("README.md").write_text(
    "\n".join(lines),
    encoding="utf-8"
)
