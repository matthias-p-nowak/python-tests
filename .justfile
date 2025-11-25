clean:
    find . -name '*cache_*' -print -exec rm -frv {} +
    find . -name '*egg-info' -print -exec rm -frv {} +
    find . -name '*so' -print -exec rm -frv {} +
    rm -frv .pytest_cache uv.lock .venv build dist .ruff_cache