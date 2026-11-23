// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G00017400 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// FUNCTION: BFME2 0x00017400 size=41 name=?dup_00843ef0@@YAHPBG0PAD@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
int dup_00843ef0(const unsigned short *first, const unsigned short *last, char *out)
{
	int count = last - first;
	if (count > 0)
	{
		do
		{
			*out++ = (char)*first++;
			--count;
		} while (count != 0);
	}
	return (int)out;
}

// FUNCTION: BFME2 0x00017490 size=36 name=?dup_00843fb0@@YAPADPBG0PAD@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
char *dup_00843fb0(const unsigned short *first, const unsigned short *last, char *out)
{
	for (int count = last - first; count > 0; --count)
		*out++ = (char)*first++;
	return out;
}

// FUNCTION: BFME2 0x000174C0 size=35 name=?dup_00843fe0@@YAPAGPBD0PAG@Z evidence=N:ledger tier=B hypothesis:mm1-gap-unit
unsigned short *dup_00843fe0(const char *first, const char *last, unsigned short *out)
{
	for (int count = last - first; count > 0; --count)
		*out++ = *first++;
	return out;
}

