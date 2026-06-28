class Solution:
    def fullJustify(self, words, maxWidth):
        res = []
        i = 0

        while i < len(words):
            line = []
            letters = 0

            # Collect words for the current line
            while (i < len(words) and
                   letters + len(words[i]) + len(line) <= maxWidth):
                line.append(words[i])
                letters += len(words[i])
                i += 1

            # Last line or single-word line
            if i == len(words) or len(line) == 1:
                s = " ".join(line)
                s += " " * (maxWidth - len(s))
                res.append(s)

            else:
                spaces = maxWidth - letters
                gaps = len(line) - 1

                even = spaces // gaps
                extra = spaces % gaps

                s = ""

                for j in range(gaps):
                    s += line[j]
                    s += " " * even

                    if j < extra:
                        s += " "

                s += line[-1]
                res.append(s)
        return res