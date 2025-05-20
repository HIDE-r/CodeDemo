
frag_bits = ntohs(ip->frag) & (IP_MF|IP_OFFSET);
if (0 == frag_bits) {
    goto frag_done;
}

// 第一片的特征: MF位为1，片偏移为0
// 最后一片的特征: MF位为0，片偏移不为0
if (IP_MF == frag_bits) {
    first_frag = 1;
} else if (frag_bits < IP_MF) {
    last_frag = 1;
}
