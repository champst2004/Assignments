import itertools

def cryptArithmetic():
    n = int(input("Enter number of words (excluding answer): "))
    words = []
    if n < 1:
        print("Need at least one word.")
        return
        
    for i in range(n):
        word = input(f"Enter word {i + 1}: ").strip().lower()
        words.append(word)
    
    answerWord = input("Enter the answer word: ").strip().lower()
    
    uniqueLetters = set(''.join(words) + answerWord)
    if len(uniqueLetters) > 10:
        print("Too many unique letters")
        return
    
    uniqueLetters = list(uniqueLetters)
    leadingLetters = set(word[0] for word in words + [answerWord])
    
    digits = range(10)
    
    for perm in itertools.permutations(digits, len(uniqueLetters)):
        letterToDigit = dict(zip(uniqueLetters, perm))
        
        if any(letterToDigit[letter] == 0 for letter in leadingLetters):
            continue

        nums = []
        letterValue(nums, words, letterToDigit)
        
        answerNum = 0
        for ch in answerWord:
            answerNum = answerNum * 10 + letterToDigit[ch]
        
        if sum(nums) == answerNum:
            print("Solution found:")
            for w, val in zip(words, nums):
                print(f"{w} = {val}")
            print(f"{answerWord} = {answerNum}")
            return letterToDigit
    
    print("No solution found.")
    return

def letterValue(nums, words, letterToDigit):
    for w in words:
        num = 0
        for ch in w:
            num = num * 10 + letterToDigit[ch]
        nums.append(num)

print(cryptArithmetic())