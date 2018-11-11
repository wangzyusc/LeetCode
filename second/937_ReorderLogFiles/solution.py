class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        digit_logs, letter_logs = [], []
        def is_digit_logs(log):
            segs = log.split(' ')
            return segs[1].isdigit()
        for log in logs:
            if is_digit_logs(log):
                digit_logs.append(log)
            else:
                letter_logs.append(log)
        def log_cmp(a, b):
            a_s, b_s = a.split(' '), b.split(' ')
            id_a, words_a = a_s[0], " ".join(a_s[1:])
            id_b, words_b = b_s[0], " ".join(b_s[1:])
            if words_a == words_b:
                return cmp(id_a, id_b)
            else:
                return cmp(words_a, words_b)
        letter_logs = sorted(letter_logs, cmp=log_cmp)
        return letter_logs + digit_logs
        
