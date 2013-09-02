#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>
#include <mach/board_lge.h>
#include <linux/mfd/pm8xxx/pm8921.h>
#include <linux/regulator/consumer.h>
#include "devices.h"
#include "board-fx3.h"
//#include CONFIG_BOARD_HEADER_FILE

#if defined(CONFIG_LGE_NFC)

#include <linux/nfc/pn544_lge.h>

//#define MSM_8930_GSBI8_QUP_I2C_BUS_ID 0

static struct pn544_i2c_platform_data nfc_platform_data[] = {
	{
		.ven_gpio 	= NFC_GPIO_VEN,
		.irq_gpio 	= NFC_GPIO_IRQ,
		.firm_gpio	= NFC_GPIO_FIRM,
		.sda_gpio   = NFC_GPIO_I2C_SDA,
		.scl_gpio   = NFC_GPIO_I2C_SCL ,
	},
};

static struct i2c_board_info msm_i2c_nxp_nfc_info[] = {
	{
		I2C_BOARD_INFO("pn544", NFC_I2C_SLAVE_ADDR),
		.platform_data = &nfc_platform_data,
		.irq = MSM_GPIO_TO_INT(NFC_GPIO_IRQ),
	}
};

static struct i2c_registry b2l_i2c_nfc_device __initdata = {
	I2C_SURF | I2C_FFA | I2C_FLUID | I2C_RUMI,
	MSM_8930_GSBI9_QUP_I2C_BUS_ID,
	msm_i2c_nxp_nfc_info,
	ARRAY_SIZE(msm_i2c_nxp_nfc_info),
};

static void __init lge_add_i2c_nfc_devices(void)
{
	//gpio_tlmm_config(GPIO_CFG(NFC_GPIO_FIRM, 0, GPIO_CFG_OUTPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
//	gpio_tlmm_config(GPIO_CFG(NFC_GPIO_I2C_SDA, 1, GPIO_CFG_INPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
//	gpio_tlmm_config(GPIO_CFG(NFC_GPIO_I2C_SCL, 1, GPIO_CFG_INPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
//	gpio_tlmm_config(GPIO_CFG(NFC_GPIO_VEN, 0, GPIO_CFG_OUTPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	//gpio_tlmm_config(GPIO_CFG(NFC_GPIO_IRQ, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);	
			
	i2c_register_board_info(b2l_i2c_nfc_device.bus,
				b2l_i2c_nfc_device.info,
				b2l_i2c_nfc_device.len);
}

void __init lge_add_nfc_devices(void)
{
	lge_add_i2c_nfc_devices();
}
#endif
