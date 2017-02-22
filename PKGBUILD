# Maintainer: Hans Gaiser <hansg91@gmail.com>

pkgname=dr-mnc-layers
pkgver=5
pkgrel=1
pkgdesc='Layer module for Multitask Network Cascades algorithm.'
arch=(x86_64)
license=('Apachev2.0')

depends=(
	'cuda'
	'caffe'
	'yaml-cpp'
)

makedepends=('cmake')
provides=('dr-mnc-layers')
conflicts=('dr-mnc-layers')

pkgver() {
	cd "$startdir"
	git rev-list --count master
}

prepare() {
	rm -rf "$startdir/build"
	mkdir "$startdir/build"
	cd "$startdir/build"

	cmake .. \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_INSTALL_PREFIX=/usr
}

build() {
	cd "$startdir/build"
	make
}

package() {
	cd "$startdir/build"
	make DESTDIR="$pkgdir/" install
}
