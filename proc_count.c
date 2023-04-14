#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

static int example(struct seq_file *m, void *v){
	seq_printf(m, "hello world\n");
	struct task_struct *p;
	int sqr_sum = 0;
	for_each_process(p) {
		seq_printf(m, "hello world\n");
	}
	return 0;
}

static int __init example_init(void)
{
	entry = proc_create_single("example_virtual_file", 0, NULL, example);
	pr_info("example: init\n");
	return 0;
}

static void __exit example_exit(void)
{
	proc_remove(entry);
	pr_info("example: exit\n");
}

module_init(example_init);
module_exit(example_exit);

MODULE_AUTHOR("Yadi Cao");
MODULE_DESCRIPTION("CS111 lab0 random play around");
MODULE_LICENSE("GPL");
