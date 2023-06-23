#ifndef Manacher_h
#define Manacher_h 1

#include <algorithm>

namespace library
{
template <size_t MAXLEN> struct Manacher
{
    char str[MAXLEN];
    int LPS[MAXLEN], len;

    void Init(const char *s)
    {
        len = 0;
        str[len++] = '*';
        for (int i = 0; s[i]; i++)
        {
            str[len++] = s[i];
            str[len++] = '*';
        }
        str[len] = '\0';
    }

    int GetLpsLength()
    {
        int c = 0, r = 0, ans = 0;
        for (int i = 1; i < len - 1; i++)
        {
            int _i = c - (i - c);
            if (r > i)
                LPS[i] = std::min(LPS[_i], r - i);
            else
                LPS[i] = 0;
            while (i - 1 - LPS[i] >= 0 && str[i - 1 - LPS[i]] == str[i + 1 + LPS[i]])
            {
                LPS[i]++;
            }
            if (i + LPS[i] > r)
            {
                r = i + LPS[i];
                c = i;
            }
            ans = std::max(ans, LPS[i]);
        }
        return ans;
    }
};
} // namespace library
#endif
