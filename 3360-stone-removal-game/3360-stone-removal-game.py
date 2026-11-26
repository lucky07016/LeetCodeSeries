class Solution:
    def canAliceWin(self, n: int) -> bool:
        need = 10
        alice = True

        while need > 0 and n >= need:
            n -= need
            need -= 1
            alice = not alice

        return not alice