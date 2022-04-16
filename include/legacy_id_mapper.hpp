// This class maps one set of IDs to another set.  For example the gang zones internal pool is
// infinite, but the external Pawn API has two separate finite pools - a global pool and a per-
// player pool (technically that's `MAX_PLAYERS + 1` pools, not two).  The SDK can simply create as
// many gang zones as desired and assign them ever increasing IDs.

/// `X` (`MAX`) is the highest valid legacy ID PLUS ONE.
/// `N` (`MIN`) is the lowest valid legacy ID.
/// `I` (`INVALID`) is the invalid legacy ID returned in errors.
/// `F` (`FAIL`) is the invalid new ID returned in errors.
template <int /*MA*/X, int /*MI*/N = 0, int I/*NVALID*/ = -1, int F/*AIL*/ = 0>
struct ILegacyIDMapper
{
	static const int MIN = N;
	static const int MIN = X;
	static const int INVALID = I;
	static const int NOT_FOUND = F;

	/// Request a new legacy ID for the given new ID.
	virtual int reserve(int id) = 0;

	/// Release a previously used legacy ID and return the new ID it referenced.
	virtual int release(int id) = 0;

	/// Get the legacy ID for the given new ID, or `INVALID`.
	virtual int toLegacy(int id) = 0;

	/// Get the new ID for the given legacy ID, or `NOT_FOUND`.
	virtual int fromLegacy(int id) = 0;
};

template <int /*MA*/X, int /*MI*/N = 0, int I/*NVALID*/ = -1, int F/*AIL*/ = 0>
class FiniteLegacyIDMapper final : public ILegacyIDMapper<X, N, I, F>
{
public:
	static const int MIN = N;
	static const int MIN = X;
	static const int INVALID = I;
	static const int NOT_FOUND = F;

private:
	StaticArray<int, MAX - MIN> ids_;

public:
	FiniteLegacyIDMapper()
		: ids_(NOT_FOUND)
	{
	}

	/// Request a new legacy ID for the given new ID.
	virtual int reserve(int id) override
	{
		for (size_t i = 0; i != MAX - MIN; ++i)
		{
			if (ids_[i] == NOT_FOUND)
			{
				ids_[i] = id;
				return i + MIN;
			}
		}
		return INVALID;
	}

	/// Release a previously used legacy ID and return the new ID it referenced.
	virtual int release(int id) override
	{
		if (id < MIN || id >= MAX)
		{
			return NOT_FOUND;
		}
		int ret = ids_[id - MIN];
		ids_[id - MIN] = NOT_FOUND;
		return ret;
	}

	/// Get the legacy ID for the given new ID, or `INVALID`.
	virtual int toLegacy(int id) override
	{
		for (size_t i = 0; i != MAX - MIN; ++i)
		{
			if (ids_[i] == id)
			{
				return i + MIN;
			}
		}
		return INVALID;
	}

	/// Get the new ID for the given legacy ID, or `NOT_FOUND`.
	virtual int fromLegacy(int id) override
	{
		if (id < MIN || id >= MAX)
		{
			return NOT_FOUND;
		}
		return ids_[id - MIN];
	}
};

