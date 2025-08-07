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
    leading_letters = set(word[0] for word in words + [answerWord])
    
    digits = range(10)
    
    for perm in itertools.permutations(digits, len(uniqueLetters)):
        letter_to_digit = dict(zip(uniqueLetters, perm))
        
        if any(letter_to_digit[letter] == 0 for letter in leading_letters):
            continue

        nums = []
        letterValue(nums, words, letter_to_digit)
        
        answer_num = 0
        for ch in answerWord:
            answer_num = answer_num * 10 + letter_to_digit[ch]
        
        if sum(nums) == answer_num:
            print("Solution found:")
            for w, val in zip(words, nums):
                print(f"{w} = {val}")
            print(f"{answerWord} = {answer_num}")
            return letter_to_digit
    
    print("No solution found.")
    return

def letterValue(nums, words, letter_to_digit):
    for w in words:
        num = 0
        for ch in w:
            num = num * 10 + letter_to_digit[ch]
        nums.append(num)

print(cryptArithmetic())