scores = [] 
for _ in range(8):
    score = int(input())
    scores.append(score)

score_tuples = [(score, i + 1) for i, score in enumerate(scores)]

score_tuples.sort(reverse=True)

total_score = 0
included_problems = []

for score, problem in score_tuples[:5]:
    total_score += score
    included_problems.append(problem)

print(total_score)
print(' '.join(str(problem) for problem in sorted(included_problems)))
