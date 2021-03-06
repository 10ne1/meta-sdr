SUMMARY = "Universal Hardware Driver for Ettus Research products."
HOMEPAGE = "http://www.ettus.com"
LICENSE = "GPLv3+"
LIC_FILES_CHKSUM = "file://LICENSE;md5=8255adf1069294c928e0e18b01a16282"

DEPENDS = "git-native python-mako-native boost libusb1 uhd-firmware \
           ncurses udev python-requests"
RDEPENDS_${PN} += "uhd-firmware python-requests"

inherit cmake pythonnative

PACKAGES =+ "${PN}-tests ${PN}-examples ${PN}-e1xx"

INSANE_SKIP_${PN} = "dev-so"

FILES_${PN} += "${libdir}/libuhd.so \
                ${libdir}/uhd/utils/*"
FILES_${PN}-tests += "${datadir}/uhd/tests/*"
FILES_${PN}-dev += "${libdir}/cmake/*"
FILES_${PN}-dbg += "${libdir}/uhd/examples/.debug/* \
                    ${libdir}/uhd/utils/.debug/* \
                    ${libdir}/uhd/utils/latency/.debug/* \
                    ${libdir}/uhd/tests/.debug/* \
                    ${libdir}/uhd/usrp_e_utils/.debug/*"
FILES_${PN}-examples = "${libdir}/uhd/examples/*"

PACKAGECONFIG ??= "gpsd"
PACKAGECONFIG[orc] = "-DENABLE_ORC=ON,-DENABLE_ORC=OFF,orc orc-native"
PACKAGECONFIG[gpsd] = "-DENABLE_GPSD=ON,-DENABLE_GPSD=OFF,gpsd"

EXTRA_OECMAKE = "-DENABLE_E100=TRUE -DENABLE_E300=TRUE -DENABLE_UHD=TRUE"

