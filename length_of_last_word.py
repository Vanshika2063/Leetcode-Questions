def lengthOfLastWord(str):
    count = 0
    x = str.split()
    index = len(x)-1
    count = len(x[index])
    return count

def main():
    str = input("Enter a string: ")
    ans = lengthOfLastWord(str)
    print(ans)

main()