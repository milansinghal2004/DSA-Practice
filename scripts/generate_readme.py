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
        # Non-LeetCode filenames (e.g. gfg-next-greater-element)
        return filename.replace("-", " ").title()

folders = []

for item in root.iterdir():
    if item.is_dir() and item.name[:4].isdigit():
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
                "date": item.name,
                "count": len(files),
                "files": files,
            }
        )

folders.sort(key=lambda x: x["date"], reverse=True)

dates = sorted(
    datetime.strptime(folder["date"], "%Y-%m-%d").date()
    for folder in folders
)

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

    # Current streak (from latest date backwards)
    current_streak = 1

    for i in range(len(dates) - 1, 0, -1):
        if (dates[i] - dates[i - 1]).days == 1:
            current_streak += 1
        else:
            break

total_questions = sum(x["count"] for x in folders)
total_days = len(folders)

lines = []

lines.append("# 🚀 DSA Practice\n")

lines.append("## 📊 Stats\n")
lines.append(f"- 📅 Total Days Practiced: **{total_days}**")
lines.append(f"- 📝 Total Questions Solved: **{total_questions}**")
lines.append(f"- 🔥 Current Streak: **{current_streak} Days**")
lines.append(f"- 🏆 Longest Streak: **{longest_streak} Days**")
lines.append(f"- 🕒 Last Updated: **{datetime.now().strftime('%Y-%m-%d %H:%M')}**\n")

lines.append("---\n")
lines.append("## 📅 Daily Progress\n")

# Summary table
lines.append("| Date | Count |")
lines.append("|------|------:|")

for folder in folders:
    lines.append(f"| {folder['date']} | {folder['count']} |")

lines.append("")

# Expandable sections
for folder in folders:
    count = folder["count"]
    problem_word = "Problem" if count == 1 else "Problems"

    lines.append("<details>")
    lines.append(
        f"<summary><strong>{folder['date']} ({count} {problem_word})</strong></summary>"
    )
    lines.append("")

    for problem in folder["files"]:
        lines.append(f"- ✅ {problem}")

    lines.append("")
    lines.append("</details>")
    lines.append("")

lines.append("---")

Path("README.md").write_text("\n".join(lines), encoding="utf-8")
