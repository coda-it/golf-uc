.PHONY: version
version:
	git tag $(V)
	./scripts/changelog.sh
	git add ./docs/changelogs/CHANGELOG_$(V).md
	./scripts/version.sh $(V)
	git add ./main/version.h
	git commit --allow-empty -m "Build $(V)"
	git tag --delete $(V)
	git tag $(V)

.PHONY: fix
fix:
	clang-format -i -style=file ./main/*.ino ./main/**/*.h

.PHONY: help
help:
	@echo  'Available tasks:'
	@echo  '* Release:'
	@echo  '- version         - Phony task. Creates changelog from latest'
	@echo  '                    git tag till the latest commit. Creates commit'
	@echo  '                    with given version (as argument) and tags'
	@echo  '                    this commit with this version. Version has to'
	@echo  '                    be passed as `V` argument with ex. `v0.0.0`'
	@echo  '                    format'
	@echo  ''

