<script async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"></script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [["\\(","\\)"] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

# 問題

漸化式 
$$
m_i = c_1m_{i-1} + c_2m_{i-2}
$$
が重解 r を持ち、特性多項式が
$$
r - c_1r - c_2
$$
で与えられるとき、一般項が
$$
m_i = ((i-1)m_0 + i\frac{m_1}{r})r^i
$$
で表されることを証明



# 解答

重解 r を持つため一般項は
$$
m_i = (A + B_i)r^i \tag{1}
$$
の形になる。( https://mathtrain.jp/sankoukan を参照 )

i = 0, 1 を上の式に代入
$$
m_0 = A \tag{2}
$$

$$
m_1 = (A + B)r\\ \tag{3}
$$

$$
(2)(3) より \\
B = \frac{m_1-m_0r}{r} \tag{4}
$$


$$
\begin{equation*}
\begin{split}
&(1)(2)(4) より \\
m_i &= (m_0 + i\frac{m_1-m_0r}{r})r^i\\
&= (m_0 + \frac{im_1}{r} - m_0i)r^i\\
&= ((i-1)m_0 + i\frac{m_1}{r})r^1
\end{split}
\end{equation*}
$$
